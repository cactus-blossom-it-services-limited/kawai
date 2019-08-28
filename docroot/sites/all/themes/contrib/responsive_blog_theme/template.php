<?php

/**
 * @file
 * Process theme data.
 */

/**
 * Add placeholder to search form.
 */
function responsive_blog_theme_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = t('Search');
  }
}

/**
 * Add current page in breadcrumbs.
 */
function responsive_blog_theme_breadcrumb(&$variables) {
  if (variable_get('responsive_blog_theme_breadcrumbs', 0) == 1) {
    $breadcrumb = $variables['breadcrumb'];
    if (!empty($breadcrumb)) {
      $breadcrumb[] = drupal_get_title();
      return implode(' / ', $breadcrumb);
    }
  }
}

/**
 * Add new class with info about page.
 */
function responsive_blog_theme_preprocess_page(&$variables) {
  // Remind user to save theme settings.
  global $user;
  if ($user->uid == 1) {
    if (empty(variable_get('theme_responsive_blog_theme_settings', ''))) {
      $substitution = array(
        '@link' => '/admin/appearance/settings/responsive_blog_theme',
      );
      $message = t('Do not forget to <a href="@link">save theme settings</a> in order to get properly working theme.', $substitution);
      drupal_set_message($message, 'warning', FALSE);
    }
  }

  $page = $variables['page'];
  $node_list_classes = 'not-node-page';

  if (isset($page['content']['system_main']['nodes'])) {
    $nodes = $page['content']['system_main']['nodes'];
    $nodes_keys = array_keys($nodes);
    // Is a empty node page?
    if (!empty(array_diff($nodes_keys, array('#suffix', '#prefix')))) {
      $not_teaser = TRUE;
      foreach ($nodes as $node) {
        if (isset($node['body'])) {
          if ($node['body']['#view_mode'] === 'teaser') {
            $not_teaser = FALSE;
            break;
          }
        }
      }
      if ($not_teaser) {
        $node_list_classes = 'node-page';
      }
      else {
        $node_list_classes = 'node-list-page';
      }
    }
  }
  else {
    if (function_exists('views_get_page_view') && views_get_page_view()) {
      // If Views page.
      $markup = $page['content']['system_main']['main']['#markup'];

      if (substr_count($markup, 'view-mode-teaser') > 0) {
        $node_list_classes = 'node-list-page';
      }
    }
  }
  $variables['node_list_classes'] = $node_list_classes;

  if (drupal_is_front_page()) {
    $variables['site_logo'] = '<img src="' . $variables['logo'] . '">';
  }
}

/**
 * Format post date for nodes.
 */
function responsive_blog_theme_preprocess_node(&$variables) {
  $node = $variables['node'];
  $substitution = array(
    '@date' => date('D, m/d/Y —  G:i', $node->created),
  );
  $submitted  = t('Posted on @date by', $substitution) . ' ' . $variables['name'];
  $variables['submitted'] = $submitted;

  $field_image = field_view_field('node', $node, 'field_image');
  if ($variables['view_mode'] == 'full') {
    $variables['node_image'] = render($field_image);
  }
  else {
    $node_image = l(render($field_image), $variables['node_url'], array('html' => TRUE));
    $variables['node_image'] = $node_image;
  }
}

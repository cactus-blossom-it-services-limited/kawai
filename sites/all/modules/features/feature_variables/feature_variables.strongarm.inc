<?php
/**
 * @file
 * feature_variables.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_variables_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_block_count';
  $strongarm->value = 3;
  $export['comment_block_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_pattern';
  $strongarm->value = '';
  $export['pathauto_node_blog_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_page_pattern';
  $strongarm->value = '[node:title]';
  $export['pathauto_node_page_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_pattern';
  $strongarm->value = '[node:created:custom:d]/[node:created:custom:m]/[node:created:custom:Y]/[node:title]';
  $export['pathauto_node_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_blog_theme_breadcrumbs';
  $strongarm->value = 0;
  $export['responsive_blog_theme_breadcrumbs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'social_media_links_appearance';
  $strongarm->value = array(
    'orientation' => 'h',
    'show_name' => 0,
  );
  $export['social_media_links_appearance'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'social_media_links_icon_style';
  $strongarm->value = 'responsive_theme_iconset:32';
  $export['social_media_links_icon_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'social_media_links_link_attributes';
  $strongarm->value = array(
    'target' => NULL,
    'rel' => NULL,
  );
  $export['social_media_links_link_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'social_media_links_platforms';
  $strongarm->value = array(
    'facebook' => array(
      'platform_value' => 'adcisolutions',
      'weight' => -9,
    ),
    'twitter' => array(
      'platform_value' => 'adcisolutions',
      'weight' => -8,
    ),
    'linkedin' => array(
      'platform_value' => 'company/adci-solutions',
      'weight' => -7,
    ),
  );
  $export['social_media_links_platforms'] = $strongarm;

  return $export;
}

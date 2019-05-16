<?php
/**
 * @file
 * feature_menu.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about:node/1.
  $menu_links['main-menu_about:node/1'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'identifier' => 'main-menu_about:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'customized' => 0,
  );
  // Exported menu link: main-menu_archive:archive.
  $menu_links['main-menu_archive:archive'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'archive',
    'router_path' => 'archive',
    'link_title' => 'Archive',
    'options' => array(
      'identifier' => 'main-menu_archive:archive',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'customized' => 0,
  );
  // Exported menu link: main-menu_contact:node/2.
  $menu_links['main-menu_contact:node/2'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Contact',
    'options' => array(
      'identifier' => 'main-menu_contact:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'customized' => 0,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Archive');
  t('Contact');
  t('Home');

  return $menu_links;
}

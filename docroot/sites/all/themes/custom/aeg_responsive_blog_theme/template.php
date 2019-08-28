<?php

/**
 * @file
 * Process theme data.
 */

function aeg_responsive_blog_theme_page_alter(&$page) {
    // Remove default message and it's title.
    if (
        drupal_is_front_page() &&
        isset($page['content']['system_main']['default_message']['#markup'])
    ) {
        $page['content']['system_main']['default_message']['#markup'] = '';

        // Check for the title.
        if (drupal_get_title()) {
            drupal_set_title('');
        }
    }
}

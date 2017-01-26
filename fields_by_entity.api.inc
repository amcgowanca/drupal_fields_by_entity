<?php
/**
 * @file
 * fields_by_entity.api.inc
 */

/**
 * Allows other modules to alter the available entity types and bundles.
 *
 * The purpose of this module is to retrict the use of entity types and their
 * bundles to allow for a better experience for field creation.
 *
 * @param array $entity_type_options
 *   An array of entity type options to make available for field configuration
 *   settings.
 * @param array $entity_bundle_options
 *   An array of bundles, keyed by the entity type.
 */
function hook_fields_by_entity_allowed_entity_types_alter(array &$entity_type_options, array &$entity_bundle_options) {
  $allowed_types = array('my_custom_entity', 'node');
  foreach ($entity_type_options as $entity_type => $entity_info) {
    if (!in_array($entity_type, $allowed_types)) {
      unset($entity_type_options[$entity_type]);
    }
  }
}

/**
 * Allows other modules to alter the individual field item element.
 *
 * @param array $item_element
 *   The item's element to alter.
 * @param EntityDrupalWrapper $item
 *   The item's entity wrapper.
 * @param EntityDrupalWrapper $parent_wrapper
 *   The parent entity wrapper of the $item.
 * @param array $field_info
 *   An array containing the field context information. The following items are
 *   available within this array:
 *     - 'field': The field definition.
 *     - 'instance': The field's instance.
 *     - 'langcode': The langcode specified for rendering this field.
 */
function hook_fields_by_entity_widget_form_item_alter(&$item_element, EntityDrupalWrapper $item, EntityDrupalWrapper $parent_wrapper, array $field_info = array()) {
  $item_element['#prefix'] = '<div class="some-css-class">Here is my item altered.</div>';
}

/**
 * Allows other modules to alter the individual item for rendering.
 *
 * @param array $element
 *   The item's element to alter.
 * @param \EntityDrupalWrapper $item
 *   The item's entity wrapper.
 * @param array $context
 *   An array containing the field context information. The following items are
 *   available within this array:
 *     - 'field': The field definition.
 *     - 'instance': The field's instance.
 *     - 'langcode': The langcode specified for rendering this field.
 */
function hook_fields_by_entity_formatter_item_alter(&$element, EntityDrupalWrapper $item, array $context = array()) {
  $item_element['prefix'] = '<div class="some-css-class">My formatted element prefix.</div>';
}

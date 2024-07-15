<?php

/**
 * @file
 * TN or RELS-EXT datastream access override callback.
 */

/**
 * Implements callback_islandora_access_override_datastream_handler().
 */
function islandora_ip_embargo_thumbnail_access_callback($op, AbstractDatastream $datastream, $user) {
  module_load_include('inc', 'islandora_ip_embargo', 'includes/utilities');
  $restrict_access = islandora_ip_embargo_restrict_access($datastream->parent->id);
  if ($restrict_access) {
    // If we're looking for a thumbnail or RELS-EXT file let it through; otherwise, deny.
    return $datastream->id == 'TN' || $datastream->id == 'RELS-EXT';
  }

  // If we found no issues we let things proceed.
  return NULL;
}

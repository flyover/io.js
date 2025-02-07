#ifndef SRC_NODE_VERSION_H_
#define SRC_NODE_VERSION_H_

#define NODE_MAJOR_VERSION 1
#define NODE_MINOR_VERSION 8
#define NODE_PATCH_VERSION 5

#define NODE_VERSION_IS_RELEASE 0

#ifndef NODE_STRINGIFY
#define NODE_STRINGIFY(n) NODE_STRINGIFY_HELPER(n)
#define NODE_STRINGIFY_HELPER(n) #n
#endif

#ifndef NODE_TAG
# if NODE_VERSION_IS_RELEASE
#  define NODE_TAG ""
# else
#  define NODE_TAG "-pre"
# endif
#endif

# define NODE_VERSION_STRING  NODE_STRINGIFY(NODE_MAJOR_VERSION) "." \
                              NODE_STRINGIFY(NODE_MINOR_VERSION) "." \
                              NODE_STRINGIFY(NODE_PATCH_VERSION)     \
                              NODE_TAG

#define NODE_VERSION "v" NODE_VERSION_STRING


#define NODE_VERSION_AT_LEAST(major, minor, patch) \
  (( (major) < NODE_MAJOR_VERSION) \
  || ((major) == NODE_MAJOR_VERSION && (minor) < NODE_MINOR_VERSION) \
  || ((major) == NODE_MAJOR_VERSION && \
      (minor) == NODE_MINOR_VERSION && (patch) <= NODE_PATCH_VERSION))

/**
 * When this version number is changed, node.js will refuse
 * to load older modules.  This should be done whenever
 * an API is broken in the C++ side, including in v8 or
 * other dependencies.
 */
#define NODE_MODULE_VERSION 43  /* io.js v1.1.0 */

#endif  /* SRC_NODE_VERSION_H_ */

# `gtree`
Small program to make and generate text-based tree structures

# How to use
1. Download a release package from this repository.
1. Execute `gtree` in a terminal window.

# How to develop
1. Your preferred Linux distro with a desktop/window manager installed.
1. Install vscode.
1. Install these extensions:
   1. C/C++ (https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
1. If you have a reasonable Linux distribution, gcc/g++ should be included, but if not, install it.
   * The gcc/g++ compiler is available via most package managers.
1. Clone this repository and open the root folder in vscode.

# How to debug
1. From the menu bar at the top of vscode, choose Run > Start Debugging (or hit F5).
   - Starting debugging will automatically perform a debug build first.

**NOTE**: I have observed tasks.json not working when cloned from a repository. The workaround was to delete it, configure a new tasks.json file, then copy the contents of the original file into the newly created one.

# Data structure
The data structure used by gtree is a combination of a tree and circular list.

### Node structure:
1. Reference to a parent node, if it exists.
1. Reference to the next node in the circular list.
   * For queues of size 1, this is a reference to itself.
1. Reference to the previous node in the circular list.
   * For queues of size 1, the is a reference to itself.
1. Reference to a child node, if it exists.

### Notes:
* Only a single node in the circular queue has a parent.
* The root node is specifically defined as having no parent node or other nodes in its list. (i.e. parent, prev, and next are all null)

### Visual:
```
[parent]
   |    [next]
   |   /      \
 [node]        [...]
   |   \      /
   |    [prev]
[child]
```
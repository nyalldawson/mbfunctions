TEMPLATE = subdirs
SUBDIRS = src/common src/dll src/test
dll.depends = src/common
test.depends = src/common
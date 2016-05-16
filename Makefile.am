bin_PROGRAMS = test

test_SOURCES = test.c

CLEANFILES = version.h

test.$(OBJEXT): version.h
.PHONY: update_version_h
version.h: update_version_h
	$(UPDATE_VERSION_H)

dist-hook:
	$(DISTHOOK_VERSION_H)
	$(DISTHOOK_VERSION)

if FIXED_VERSION

UPDATE_VERSION_H = \
	[ -f version.h ] || $(LN_S) "$(srcdir)/version.h.in" version.h

DISTHOOK_VERSION_H = \
	cp "$(srcdir)/version.h.in" "$(distdir)/version.h.in"

DISTHOOK_VERSION = \
	cp "$(srcdir)/.version" "$(distdir)/.version"

else

UPDATE_VERSION_H = \
	$(SHELL) "$(top_srcdir)/scripts/git-version-gen.sh" -C "$(srcdir)" -c -o version.h

DISTHOOK_VERSION_H = \
	$(SHELL) "$(top_srcdir)/scripts/git-version-gen.sh" -C "$(srcdir)" -c -o "$(distdir)/version.h.in"

DISTHOOK_VERSION = \
	$(SHELL) "$(top_srcdir)/scripts/git-version-gen.sh" -C "$(srcdir)" -v -o "$(distdir)/.version"

endif

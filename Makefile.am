bin_PROGRAMS = test

test_SOURCES = test.c

CLEANFILES = version.h

test.$(OBJEXT): version.h
.PHONY: update_version_h
version.h: update_version_h
	$(UPDATE_VERSION_H)

dist-hook:
	$(DISTHOOK_VERSION_H)

UPDATE_VERSION_H = \
	if [ -f $(srcdir)/version.h.in ]; then \
		[ -f version.h ] || $(LN_S) $(srcdir)/version.h.in version.h; \
	else \
		$(SHELL) $(top_srcdir)/scripts/git-version-gen.sh -C "$(srcdir)" -c -o version.h; \
	fi

DISTHOOK_VERSION_H = \
	if [ -f $(srcdir)/version.h.in ]; then \
		cp $(srcdir)/version.h.in $(distdir)/version.h.in; \
	else \
		$(SHELL) $(top_srcdir)/scripts/git-version-gen.sh -C $(srcdir) -c -o $(distdir)/version.h.in; \
	fi

DISTHOOK_VERSION = \
	if [ -f $(srcdir)/.version ]; then \
		cp $(srcdir)/.version $(distdir)/.version; \
	else \
		$(SHELL) $(top_srcdir)/scripts/git-version-gen.sh -C $(srcdir) -v -o $(distdir)/.version; \
	fi

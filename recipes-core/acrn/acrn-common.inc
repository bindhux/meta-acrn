SUMMARY = "A Type 1 hypervisor stack, running directly on the bare-metal hardware"
HOMEPAGE = "https://projectacrn.org/"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://LICENSE;md5=b762ef53db85c389256a9d215053edf7"

SRC_URI = "git://github.com/projectacrn/acrn-hypervisor.git;protocol=https;branch=${SRCBRANCH}; \
"

# Snapshot tags are of the format:
# acrn-<year>w<week>.<day>-<timestamp><pass|fail>
PV = "2.7"
SRCREV = "fd223fa2e4e1568bef7ef72ced9bd5b46cecbe88"
SRCBRANCH = "release_2.7"

UPSTREAM_CHECK_GITTAGREGEX = "^v(?P<pver>\d+(\.\d+)+)$"

S = "${WORKDIR}/git"

CVE_PRODUCT = "acrn"

# y for release build, n for debug build.
ACRN_RELEASE ?= "n"

EXTRA_OEMAKE += "RELEASE=${ACRN_RELEASE} \
                 SYSROOT=${STAGING_DIR_TARGET} \
                 O=${B} \
                 DESTDIR=${D} \
                 prefix=${prefix} \
                 bindir=${bindir} \
                 libdir=${libdir} \
                 datadir=${datadir} \
                 includedir=${includedir} \
                 systemd_unitdir=${systemd_unitdir}"


# acrn supports build objects out-of-tree but builds must be performed from
# inside the source
B = "${WORKDIR}/build"
do_configure[cleandirs] = "${B}"
do_configure[dirs] = "${S}"
do_compile[dirs] = "${S}"
do_install[dirs] = "${S}"

# Fixed in v1.2 and onward
CVE_CHECK_IGNORE += "CVE-2019-18844 CVE-2021-36145"

#
# Copyright (C) 2014 - present by OpenGamma Inc. and the OpenGamma group of companies
#
# Please see distribution for license.
#

import unittest
from copy import deepcopy
from combine import read_version_info, validate_version_info, construct_combined_verinfo

class TestVerinfo(unittest.TestCase):

    def test_read_version_info(self):
        self.maxDiff = None
        verinfos = read_version_info(['test-verinfo.zip'])
        # Compare read dicts. This is a little fiddly because we are stuck on 2.6 with no
        # assertSequenceEqual.
        # Check we read one verinfo
        self.assertEqual(1, len(verinfos.keys()))
        # Get that verinfo and check the length of its keys
        verinfo = verinfos[verinfos.keys()[0]]
        self.assertEqual(7, len(verinfo.keys()))
        # Check root keys
        for k in ('artifacts', 'buildnumber', 'platforms', 'project', 'revision', 'version'):
            self.assertEqual(VERINFO_LNX_REFERENCE[k], verinfo[k])
        # Check keys in subprojects
        for k in ('buildnumber', 'platforms', 'project', 'revision'):
            self.assertEqual(VERINFO_LNX_REFERENCE['subprojects'][0][k], verinfo['subprojects'][0][k])

    def test_validate_version_info(self):
        validate_version_info(VERINFO_REFERENCES)

    def test_invalid_version_info(self):
        def make_bad(key):
            refs = deepcopy(VERINFO_REFERENCES)
            refs['lnx'][key] = 'bad'
            return refs

        self.assertRaises(ValueError, validate_version_info, make_bad('project'))
        self.assertRaises(ValueError, validate_version_info, make_bad('version'))
        self.assertRaises(ValueError, validate_version_info, make_bad('revision'))

        def make_bad_subproject(key):
            refs = deepcopy(VERINFO_REFERENCES)
            refs['lnx']['subprojects'][0][key] = 'bad'
            return refs

        self.assertRaises(ValueError, validate_version_info, make_bad_subproject('project'))
        self.assertRaises(ValueError, validate_version_info, make_bad_subproject('revision'))

VERINFO_LNX_REFERENCE = \
{'artifacts': ['jars/og-maths-lnx-0.1.0-SNAPSHOT.jar',
               'jars/og-maths-lnx-0.1.0-SNAPSHOT-javadoc.jar',
               'jars/og-maths-lnx-0.1.0-SNAPSHOT-sources.jar',
               'jars/og-maths-lnx-0.1.0-SNAPSHOT-tests.jar'],
 'buildnumber': 25,
 'platforms': ['lnx'],
 'project': 'OG-Maths',
 'revision': 'a57fd89cfcb8b2c6711f6ec8bac19bb339cc24bc',
 'subprojects': [{'buildnumber': 9,
                  'platforms': ['lnx'],
                  'project': 'OG-Lapack',
                  'revision': '78bb7b167aea5f8b52015610d3ad69f360a84493'}],
 'version': '0.1.0-SNAPSHOT'}

VERINFO_OSX_REFERENCE = \
{'artifacts': ['jars/og-maths-osx-0.1.0-SNAPSHOT.jar',
               'jars/og-maths-osx-0.1.0-SNAPSHOT-javadoc.jar',
               'jars/og-maths-osx-0.1.0-SNAPSHOT-sources.jar',
               'jars/og-maths-osx-0.1.0-SNAPSHOT-tests.jar'],
 'buildnumber': 6,
 'platforms': ['osx'],
 'project': 'OG-Maths',
 'revision': 'a57fd89cfcb8b2c6711f6ec8bac19bb339cc24bc',
 'subprojects': [{'buildnumber': 9,
                  'platforms': ['osx'],
                  'project': 'OG-Lapack',
                  'revision': '78bb7b167aea5f8b52015610d3ad69f360a84493'}],
 'version': '0.1.0-SNAPSHOT'}

VERINFO_WIN_REFERENCE = \
{'artifacts': ['jars/og-maths-win-0.1.0-SNAPSHOT.jar',
               'jars/og-maths-win-0.1.0-SNAPSHOT-javadoc.jar',
               'jars/og-maths-win-0.1.0-SNAPSHOT-sources.jar',
               'jars/og-maths-win-0.1.0-SNAPSHOT-tests.jar'],
 'buildnumber': 7,
 'platforms': ['win'],
 'project': 'OG-Maths',
 'revision': 'a57fd89cfcb8b2c6711f6ec8bac19bb339cc24bc',
 'subprojects': [{'buildnumber': 10,
                  'platforms': ['win'],
                  'project': 'OG-Lapack',
                  'revision': '78bb7b167aea5f8b52015610d3ad69f360a84493'}],
 'version': '0.1.0-SNAPSHOT'}

VERINFO_REFERENCES = { 'lnx': VERINFO_LNX_REFERENCE, 'osx': VERINFO_OSX_REFERENCE, 'win': VERINFO_WIN_REFERENCE }

if __name__ == '__main__':
    unittest.main()

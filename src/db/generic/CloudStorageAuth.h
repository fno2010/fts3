/*
 * Copyright (c) CERN 2013-2015
 *
 * Copyright (c) Members of the EMI Collaboration. 2010-2013
 *  See  http://www.eu-emi.eu/partners for details on the copyright
 *  holders.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef CLOUDSTORAGEAUTH_H_
#define CLOUDSTORAGEAUTH_H_

#include <string>

struct CloudStorageAuth
{
    std::string cloudName;
    std::string appKey;
    std::string appSecret;
    std::string accessToken;       ///< Access key for S3
    std::string accessTokenSecret; ///< Secret key for S3
    std::string requestToken;      ///< Session token for S3 (short term credentials)
    std::string osToken;           ///< OS token for Swift
    std::string osProjectID;       ///< OS project ID for Swift
};

#endif // CLOUDSTORAGEAUTH_H_

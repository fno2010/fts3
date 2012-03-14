/*
 *	Copyright notice:
 *	Copyright © Members of the EMI Collaboration, 2010.
 *
 *	See www.eu-emi.eu for details on the copyright holders
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 *
 * JobIDCli.h
 *
 *  Created on: Mar 13, 2012
 *      Author: Michal Simon
 */

#ifndef JOBIDCLI_H_
#define JOBIDCLI_H_

#include "CliBase.h"
#include <vector>
#include <string>

using namespace std;

namespace fts3 { namespace cli {

/**
 * JobIDCli is the command line utility used for retreiving job IDs.
 *
 * In addition to the inherited functionalities from CliBase the SubmitTransferCli class provides:
 * 		- job ID (--jobid), positional parameter (passed without any switch option)
 *
 * @see CliBase
 */
class JobIDCli: public CliBase {
public:

	/**
	 * Default constructor.
	 *
	 * Creates the command line interface for retrieving job IDs. Job ID is
	 * market as both: hidden and positional
	 */
	JobIDCli();

	/**
	 * Destructor.
	 */
	virtual ~JobIDCli();

	/**
	 * Gives the instruction how to use the command line tool.
	 *
	 * @return a string with instruction on how to use the tool
	 */
	string getUsageString(string tool);

	/**
	 * Gets a vector with job IDs.
	 *
	 * @return if job IDs were given as command line parameters a
	 * 			vector containing job IDs otherwise an empty vector
	 */
	vector<string> getJobIds();
};

}
}

#endif /* JOBIDCLI_H_ */

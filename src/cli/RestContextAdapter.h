/*
 * RestContextAdapter.h
 *
 *  Created on: 15 Aug 2014
 *      Author: simonm
 */

#ifndef RESTCONTEXTADAPTER_H_
#define RESTCONTEXTADAPTER_H_

#include "ServiceAdapter.h"

#include "Snapshot.h"
#include "JobStatus.h"

#include <string>
#include <vector>

namespace fts3
{
namespace cli
{

class RestContextAdapter : public ServiceAdapter
{

public:
    RestContextAdapter(std::string const & endpoint, std::string const & capath, std::string const & proxy):
        ServiceAdapter(endpoint),
        capath(capath),
        proxy(proxy) {}

    virtual ~RestContextAdapter() {}

    std::vector<JobStatus> listRequests (std::vector<std::string> const & statuses, std::string const & dn, std::string const & vo, std::string const & source, std::string const & destination);

    std::vector<JobStatus> listDeletionRequests (std::vector<std::string> const & statuses, std::string const & dn, std::string const & vo, std::string const & source, std::string const & destination);

    std::vector< std::pair<std::string, std::string>  > cancel(std::vector<std::string> const & jobIds);

    boost::tuple<int, int> cancelAll(const std::string& vo);

    std::string transferSubmit (std::vector<File> const & files, std::map<std::string, std::string> const & parameters);

    std::string deleteFile (const std::vector<std::string>& filesForDelete);

    JobStatus getTransferJobStatus (std::string const & jobId, bool archive);

    JobStatus getTransferJobSummary (std::string const & jobId, bool archive);

    std::vector<FileInfo> getFileStatus (std::string const & jobId, bool archive, int offset, int limit, bool retries);

    /**
     * @param jobId : job ID
     * @return : vector containing detailed information about files in the given job (including file ID)
     */
    std::vector<DetailedFileStatus> getDetailedJobStatus(std::string const & jobId);

    /**
     * @param vo : user VO name
     * @param src : source SE
     * @param dst : destination SE
     *
     * @return the snapshot
     */
    std::vector<Snapshot> getSnapShot(std::string const & vo, std::string const & src, std::string const & dst);

    void delegate(std::string const & delegationId, long expirationTime);

private:

    void getInterfaceDetails();

    std::string const capath;
    std::string const proxy;
};

} /* namespace cli */
} /* namespace fts3 */

#endif /* RESTCONTEXTADAPTER_H_ */

/*
 * PythonProxyDelegator.cpp
 *
 *  Created on: 1 Apr 2014
 *      Author: simonm
 */

#include "PythonProxyDelegator.h"

#include "delegation/SoapDelegator.h"

namespace fts3
{
namespace cli
{

PythonProxyDelegator::PythonProxyDelegator(py::str endpoint, py::str delegationId, long expTime) :
    delegator(new SoapDelegator(py::extract<std::string>(endpoint), py::extract<std::string>(delegationId), expTime, std::string()))
{

}

PythonProxyDelegator::~PythonProxyDelegator()
{

}

void PythonProxyDelegator::delegate()
{
    delegator->delegate();
}

long PythonProxyDelegator::isCertValid(void)
{
    return delegator->isCertValid();
}

}
}

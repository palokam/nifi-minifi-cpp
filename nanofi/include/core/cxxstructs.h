/**
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NIFI_MINIFI_CPP_CXXSTRUCTS_H
#define NIFI_MINIFI_CPP_CXXSTRUCTS_H

#include "cstructs.h"
#include "cxx/Plan.h"

struct flow : public ExecutionPlan {
  using ExecutionPlan::ExecutionPlan;
};

struct standalone_processor : public core::Processor {
  using core::Processor::Processor;
};

struct processor : public core::Processor {
  using core::Processor::Processor;
};

struct processor_session : public core::ProcessSession {
  using core::ProcessSession::ProcessSession;
};

#endif //NIFI_MINIFI_CPP_CXXSTRUCTS_H

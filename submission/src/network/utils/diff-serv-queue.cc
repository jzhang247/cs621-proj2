#include "diff-serv-queue.h"

namespace ns3
{
NS_LOG_COMPONENT_DEFINE("MyQueue");
NS_OBJECT_TEMPLATE_CLASS_DEFINE(DiffServQueue, Packet);
NS_OBJECT_TEMPLATE_CLASS_DEFINE(DiffServQueue, QueueDiscItem);
} // namespace ns3
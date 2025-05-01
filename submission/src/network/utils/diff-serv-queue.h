
#ifndef INCLUDED_DIFF_SERV_QUEUE_H
#define INCLUDED_DIFF_SERV_QUEUE_H

#include "queue.h"

namespace ns3
{
/**
 * @ingroup queue
 *
 * @brief A FIFO packet queue that drops tail-end packets on overflow
 */
template <typename Item>
class DiffServQueue : public Queue<Item>
{
  public:
    /**
     * @brief Get the type ID.
     * @return the object TypeId
     */
    static TypeId GetTypeId()
    {
        static TypeId tid = TypeId(GetTemplateClassName<DiffServQueue<Item>>())
                                .SetParent<Queue<Item>>()
                                .SetGroupName("Network")
                                .template AddConstructor<DiffServQueue<Item>>();
        // .AddAttribute("MaxSize",
        //               "The max queue size",
        //               QueueSizeValue(QueueSize("100p")),
        //               MakeQueueSizeAccessor(&QueueBase::SetMaxSize, &QueueBase::GetMaxSize),
        //               MakeQueueSizeChecker());
        return tid;
    }

    /**
     * @brief MyQueue Constructor
     *
     * TODO: complete
     */
    DiffServQueue()
        : Queue<Item>(),
          NS_LOG_TEMPLATE_DEFINE("MyQueue")
    {
        NS_LOG_FUNCTION(this);
    }

    ~DiffServQueue() override
    {
        NS_LOG_FUNCTION(this);
    }

    bool Enqueue(Ptr<Item> item) override;
    Ptr<Item> Dequeue() override;
    Ptr<Item> Remove() override;
    Ptr<const Item> Peek() const override;

  private:
    using Queue<Item>::GetContainer;
    using Queue<Item>::DoEnqueue;
    using Queue<Item>::DoDequeue;
    using Queue<Item>::DoRemove;
    using Queue<Item>::DoPeek;

    NS_LOG_TEMPLATE_DECLARE; //!< redefinition of the log component
};

template <typename Item>
bool
DiffServQueue<Item>::Enqueue(Ptr<Item> item)
{
    NS_LOG_FUNCTION(this << item);
    return DoEnqueue(GetContainer().end(), item);
}

template <typename Item>
Ptr<Item>
DiffServQueue<Item>::Dequeue()
{
    NS_LOG_FUNCTION(this);

    Ptr<Item> item = DoDequeue(GetContainer().begin());

    NS_LOG_LOGIC("Popped " << item);

    return item;
}

template <typename Item>
Ptr<Item>
DiffServQueue<Item>::Remove()
{
    NS_LOG_FUNCTION(this);

    Ptr<Item> item = DoRemove(GetContainer().begin());

    NS_LOG_LOGIC("Removed " << item);

    return item;
}

template <typename Item>
Ptr<const Item>
DiffServQueue<Item>::Peek() const
{
    NS_LOG_FUNCTION(this);

    return DoPeek(GetContainer().begin());
}

// The following explicit template instantiation declarations prevent all the
// translation units including this header file to implicitly instantiate the
// MyQueue<Packet> class and the MyQueue<QueueDiscItem> class. The
// unique instances of these classes are explicitly created through the macros
// NS_OBJECT_TEMPLATE_CLASS_DEFINE (MyQueue,Packet) and
// NS_OBJECT_TEMPLATE_CLASS_DEFINE (MyQueue,QueueDiscItem), which are included
// in diff-serv-queue.cc
extern template class DiffServQueue<Packet>;
extern template class DiffServQueue<QueueDiscItem>;

} // namespace ns3
#endif
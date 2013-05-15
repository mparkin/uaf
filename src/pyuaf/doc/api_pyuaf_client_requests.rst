``pyuaf.client.requests``
====================================================================================================

.. automodule:: pyuaf.client.requests




*class* AsyncCreateMonitoredDataRequest
----------------------------------------------------------------------------------------------------

.. autoclass:: pyuaf.client.requests.AsyncCreateMonitoredDataRequest
    
    An :class:`~pyuaf.client.requests.AsyncCreateMonitoredDataRequest` is an asynchronous request 
    to create one or more monitored data items.
    
    This class has the exact same methods and attributes as a 
    :class:`~pyuaf.client.requests.CreateMonitoredDataRequest`, so see the documentation
    of the latter.



*class* AsyncCreateMonitoredEventsRequest
----------------------------------------------------------------------------------------------------

.. autoclass:: pyuaf.client.requests.AsyncCreateMonitoredEventsRequest
    
    An :class:`~pyuaf.client.requests.AsyncCreateMonitoredEventsRequest` is an asynchronous request 
    to create one or more monitored event items.
    
    This class has the exact same methods and attributes as a 
    :class:`~pyuaf.client.requests.CreateMonitoredEventsRequest`, so see the documentation
    of the latter.



*class* AsyncMethodCallRequest
----------------------------------------------------------------------------------------------------

.. autoclass:: pyuaf.client.requests.AsyncMethodCallRequest
    
    An :class:`~pyuaf.client.requests.AsyncMethodCallRequest` is an asynchronous request 
    to call one or more methods.
    
    This class has the exact same methods and attributes as a 
    :class:`~pyuaf.client.requests.MethodCallRequest`, so see the documentation
    of the latter.



*class* AsyncReadRequest
----------------------------------------------------------------------------------------------------

.. autoclass:: pyuaf.client.requests.AsyncReadRequest
    
    An :class:`~pyuaf.client.requests.AsyncReadRequest` is an asynchronous request 
    to read an attribute of one or more nodes.
    
    This class has the exact same methods and attributes as a 
    :class:`~pyuaf.client.requests.ReadRequest`, so see the documentation
    of the latter.



*class* AsyncWriteRequest
----------------------------------------------------------------------------------------------------

.. autoclass:: pyuaf.client.requests.AsyncWriteRequest
    
    An :class:`~pyuaf.client.requests.AsyncWriteRequest` is an asynchronous request 
    to write an attribute of one or more nodes.
    
    This class has the exact same methods and attributes as a 
    :class:`~pyuaf.client.requests.WriteRequest`, so see the documentation
    of the latter.



*class* CreateMonitoredDataRequest
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.CreateMonitoredDataRequest

    A :class:`~pyuaf.client.requests.CreateMonitoredDataRequest` is a synchronous request to 
    create one or more monitored data items.
    
    * Methods:

        .. automethod:: pyuaf.client.requests.CreateMonitoredDataRequest.__init__
    
            Create a new CreateMonitoredDataRequest object.
            
            :param targets: The targets of the request, either as:
            
                             - an ``int``, specifying the number of targets (0 by default)
                             - a single target (a :class:`~pyuaf.client.requests.CreateMonitoredDataRequestTarget`)
                             - a vector of targets (a :class:`~pyuaf.client.requests.CreateMonitoredDataRequestTargetVector`)
    
            :param serviceConfig: The config for the service settings.
            :type serviceConfig: :class:`~pyuaf.client.configs.CreateMonitoredDataConfig`
    
            :param sessionConfig: The config containing the session settings.
            :type sessionConfig: :class:`~pyuaf.client.configs.SessionConfig`
    
            :param subscriptionConfig: The config containing the subscription settings.
            :type subscriptionConfig: :class:`~pyuaf.client.configs.SubscriptionConfig`
    
        .. method:: __str__()
    
            Get a formatted string representation of the request.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequest.targets

            The targets, as a :class:`~pyuaf.client.requests.CreateMonitoredDataRequestTargetVector`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequest.serviceConfig

            The service config, as a :class:`~pyuaf.client.configs.CreateMonitoredDataConfig`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequest.sessionConfig

            The session config, as a :class:`~pyuaf.client.configs.SessionConfig`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequest.subscriptionConfig

            The subscription config, as a :class:`~pyuaf.client.configs.SubscriptionConfig`.


*class* CreateMonitoredDataRequestTarget
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.CreateMonitoredDataRequestTarget

    A :class:`~pyuaf.client.requests.CreateMonitoredDataRequestTarget` is the part of 
    a :class:`~pyuaf.client.requests.CreateMonitoredDataRequest` that specifies the target to be 
    monitored.

    
    * Methods:

        .. method:: __init__(args*)
    
            Create a new CreateMonitoredDataRequestTarget object.
            
            The default 
              - attributeId is :attr:`~pyuaf.util.attributeids.Value`
              - monitoringMode is :attr:`~pyuaf.util.monitoringmodes.Reporting`
              - samplingIntervalSec is 0.0
              - queueSize is 0
              - discardOldest is False.
            
    
        .. method:: __str__()
    
            Get a formatted string representation of the target.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.address

            The address of the node of which the attribute will be monitored, 
            as a :class:`~pyuaf.util.Address`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.attributeId

            The attribute id to be monitored, as an ``int`` defined 
            in :mod:`~pyuaf.util.attributeids`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.indexRange
    
            The index range (as a ``str``), in case you want to partially monitor an array.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.monitoringMode

            The monitoring mode, as an ``int`` defined in :mod:`~pyuaf.util.monitoringmodes`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.samplingIntervalSec

            The rate, in seconds (as a ``float``), at which the monitored item should be sampled 
            by the server. 0.0 means as fast as possible.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.queueSize

            The size of the queue at the server side, as an ``int``.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.discardOldest

            ``bool``: Discard the oldest item in the queue, or not.

        .. autoattribute:: pyuaf.client.requests.CreateMonitoredDataRequestTarget.dataChangeFilter

            The data change filter settings, as a :class:`~pyuaf.util.DataChangeFilter`.



*class* CreateMonitoredDataRequestTargetVector
----------------------------------------------------------------------------------------------------


.. class:: pyuaf.client.requests.CreateMonitoredDataRequestTargetVector

    An CreateMonitoredDataRequestTargetVector is a container that holds elements of type 
    :class:`pyuaf.client.requests.CreateMonitoredDataRequestTarget`. 
    It is an artifact automatically generated from the C++ UAF code, and has the same functionality
    as a ``list`` of :class:`~pyuaf.client.requests.CreateMonitoredDataRequestTarget`.

    Usage example:
    
    .. doctest::
    
        >>> import pyuaf
        >>> from pyuaf.client.requests import CreateMonitoredDataRequestTarget, CreateMonitoredDataRequestTargetVector
        >>> from pyuaf.util            import Address, ExpandedNodeId
        
        >>> # construct a vector without elements:
        >>> vec = CreateMonitoredDataRequestTargetVector()
        >>> noOfElements = len(vec) # will be 0
        
        >>> vec.append(CreateMonitoredDataRequestTarget())
        >>> noOfElements = len(vec) # will be 1
        >>> vec[0].address   = Address(ExpandedNodeId("SomeId", "SomeNs", "SomeServerUri"))
        >>> vec[0].queueSize = 5
        
        >>> vec.resize(4)
        >>> noOfElements = len(vec) # will be 4
        
        >>> # you may construct a vector from a regular Python list:
        >>> otherVec = CreateMonitoredDataRequestTargetVector( [CreateMonitoredDataRequestTarget(), CreateMonitoredDataRequestTarget()] )
        
        >>> # or you may specify a number of targets directly
        >>> yetAnotherVec = CreateMonitoredDataRequestTargetVector(3)
        >>> yetAnotherVec[0].queueSize = 10
        >>> yetAnotherVec[1].queueSize = 10
        >>> yetAnotherVec[2].queueSize = 10



*class* CreateMonitoredEventsRequest
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.CreateMonitoredEventsRequest

    A :class:`~pyuaf.client.requests.CreateMonitoredEventsRequest` is a synchronous request to 
    create one or more monitored event items.
    
    * Methods:

        .. automethod:: pyuaf.client.requests.CreateMonitoredEventsRequest.__init__
    
            Create a new CreateMonitoredEventsRequest object.
            
            :param targets: The targets of the request, either as:
            
                             - an ``int``, specifying the number of targets (0 by default)
                             - a single target (a :class:`~pyuaf.client.requests.CreateMonitoredEventsRequestTarget`)
                             - a vector of targets (a :class:`~pyuaf.client.requests.CreateMonitoredEventsRequestTargetVector`)
    
            :param serviceConfig: The config for the service settings.
            :type serviceConfig: :class:`~pyuaf.client.configs.CreateMonitoredEventsConfig`
    
            :param sessionConfig: The config containing the session settings.
            :type sessionConfig: :class:`~pyuaf.client.configs.SessionConfig`
    
            :param subscriptionConfig: The config containing the subscription settings.
            :type subscriptionConfig: :class:`~pyuaf.client.configs.SubscriptionConfig`
    
        .. method:: __str__()
    
            Get a formatted string representation of the request.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequest.targets

            The targets, as a :class:`~pyuaf.client.requests.CreateMonitoredEventsRequestTargetVector`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequest.serviceConfig

            The service config, as a :class:`~pyuaf.client.configs.CreateMonitoredEventsConfig`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequest.sessionConfig

            The session config, as a :class:`~pyuaf.client.configs.SessionConfig`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequest.subscriptionConfig

            The subscription config, as a :class:`~pyuaf.client.configs.SubscriptionConfig`.


*class* CreateMonitoredEventsRequestTarget
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget

    A :class:`~pyuaf.client.requests.CreateMonitoredEventsRequestTarget` is the part of 
    a :class:`~pyuaf.client.requests.CreateMonitoredEventsRequest` that specifies the target to be 
    monitored.

    
    * Methods:

        .. method:: __init__(args*)
    
            Create a new CreateMonitoredEventsRequestTarget object.
            
            The default 
              - monitoringMode is :attr:`~pyuaf.util.monitoringmodes.Reporting`
              - samplingIntervalSec is 0.0
              - queueSize is 0
              - discardOldest is False.
            
    
        .. method:: __str__()
    
            Get a formatted string representation of the target.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget.address

            The address of the node of which the attribute will be monitored, 
            as a :class:`~pyuaf.util.Address`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget.monitoringMode

            The monitoring mode, as an ``int`` defined in :mod:`~pyuaf.util.monitoringmodes`.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget.samplingIntervalSec

            The rate, in seconds (as a ``float``), at which the monitored item should be sampled 
            by the server. 0.0 means as fast as possible.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget.queueSize

            The size of the queue at the server side, as an ``int``.
    
        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget.discardOldest

            ``bool``: Discard the oldest item in the queue, or not.

        .. autoattribute:: pyuaf.client.requests.CreateMonitoredEventsRequestTarget.eventFilter

            The event filter settings, as an :class:`~pyuaf.util.EventFilter`.



*class* CreateMonitoredEventsRequestTargetVector
----------------------------------------------------------------------------------------------------


.. class:: pyuaf.client.requests.CreateMonitoredEventsRequestTargetVector

    An CreateMonitoredEventsRequestTargetVector is a container that holds elements of type 
    :class:`pyuaf.client.requests.CreateMonitoredEventsRequestTarget`. 
    It is an artifact automatically generated from the C++ UAF code, and has the same functionality
    as a ``list`` of :class:`~pyuaf.client.requests.CreateMonitoredEventsRequestTarget`.

    Usage example:
    
    .. doctest::
    
        >>> import pyuaf
        >>> from pyuaf.client.requests import CreateMonitoredEventsRequestTarget, CreateMonitoredEventsRequestTargetVector
        >>> from pyuaf.util            import Address, ExpandedNodeId
        
        >>> # construct a vector without elements:
        >>> vec = CreateMonitoredEventsRequestTargetVector()
        >>> noOfElements = len(vec) # will be 0
        
        >>> vec.append(CreateMonitoredEventsRequestTarget())
        >>> noOfElements = len(vec) # will be 1
        >>> vec[0].address   = Address(ExpandedNodeId("SomeId", "SomeNs", "SomeServerUri"))
        >>> vec[0].queueSize = 5
        
        >>> vec.resize(4)
        >>> noOfElements = len(vec) # will be 4
        
        >>> # you may construct a vector from a regular Python list:
        >>> otherVec = CreateMonitoredEventsRequestTargetVector( [CreateMonitoredEventsRequestTarget(), CreateMonitoredEventsRequestTarget()] )
        
        >>> # or you may specify a number of targets directly
        >>> yetAnotherVec = CreateMonitoredEventsRequestTargetVector(3)
        >>> yetAnotherVec[0].queueSize = 10
        >>> yetAnotherVec[1].queueSize = 10
        >>> yetAnotherVec[2].queueSize = 10


*class* MethodCallRequest
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.MethodCallRequest

    A :class:`~pyuaf.client.requests.MethodCallRequest` is a synchronous request to call one or 
    more methods.
    
    * Methods:

        .. automethod:: pyuaf.client.requests.MethodCallRequest.__init__
    
            Create a new MethodCallRequest object.
            
            :param targets: The targets of the request, either as:
            
                             - an ``int``, specifying the number of targets (0 by default)
                             - a single target (a :class:`~pyuaf.client.requests.MethodCallRequestTarget`)
                             - a vector of targets (a :class:`~pyuaf.client.requests.MethodCallRequestTargetVector`)
    
            :param serviceConfig: The config for the service settings.
            :type serviceConfig: :class:`~pyuaf.client.configs.MethodCallConfig`
    
            :param sessionConfig: The config containing the session settings.
            :type sessionConfig: :class:`~pyuaf.client.configs.SessionConfig`
    
        .. method:: __str__()
    
            Get a formatted string representation of the request.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.MethodCallRequest.targets

            The targets, as a :class:`~pyuaf.client.requests.MethodCallRequestTargetVector`.
    
        .. autoattribute:: pyuaf.client.requests.MethodCallRequest.serviceConfig

            The service config, as a :class:`~pyuaf.client.configs.MethodCallConfig`.
    
        .. autoattribute:: pyuaf.client.requests.MethodCallRequest.sessionConfig

            The session config, as a :class:`~pyuaf.client.configs.SessionConfig`.


*class* MethodCallRequestTarget
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.MethodCallRequestTarget

    A :class:`~pyuaf.client.requests.MethodCallRequestTarget` is the part of 
    a :class:`~pyuaf.client.requests.MethodCallRequest` that specifies the target to be called.

    
    * Methods:

        .. method:: __init__(args*)
    
            Create a new MethodCallRequestTarget object.
            
            You can specify a MethodCallRequestTarget in two ways:
            
            .. doctest::
            
                >>> import pyuaf
                >>> from pyuaf.util             import Address, ExpandedNodeId, VariantVector
                >>> from pyuaf.util.primitives  import UInt32, Double
                >>> from pyuaf.client.requests  import MethodCallRequestTarget
                
                >>> objectAddress  = Address(ExpandedNodeId("someId", "someNs", "someServerUri"))
                >>> methodAddress  = Address(ExpandedNodeId("someOtherId", "someNs", "someServerUri"))
                >>> inputArguments = VariantVector()
                >>> inputArguments.append(UInt32(123))
                >>> inputArguments.append("some string")
                >>> inputArguments.append(Double(-3.14))
                
                >>> # there are 2 ways to define a target:
                >>> target0 = MethodCallRequestTarget()
                >>> target1 = MethodCallRequestTarget(objectAddress, methodAddress, inputArguments)
                
                >>> # in case of the first target, you still need to specify the addresses and arguments:
                >>> target0.objectAddress  = objectAddress
                >>> target0.methodAddress  = methodAddress
                >>> target0.inputArguments = inputArguments
    
        .. method:: __str__()
    
            Get a formatted string representation of the target.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.MethodCallRequestTarget.objectAddress

            The address of the context node of the method call, as a :class:`~pyuaf.util.Address`.
    
        .. autoattribute:: pyuaf.client.requests.MethodCallRequestTarget.methodAddress

            The address of the node representing the method, as a :class:`~pyuaf.util.Address`.
    
        .. autoattribute:: pyuaf.client.requests.MethodCallRequestTarget.inputArguments
    
            The input arguments of the method call, as a :class:`~pyuaf.util.VariantVector`.



*class* MethodCallRequestTargetVector
----------------------------------------------------------------------------------------------------


.. class:: pyuaf.client.requests.MethodCallRequestTargetVector

    An MethodCallRequestTargetVector is a container that holds elements of type 
    :class:`pyuaf.client.requests.MethodCallRequestTarget`. 
    It is an artifact automatically generated from the C++ UAF code, and has the same functionality
    as a ``list`` of :class:`~pyuaf.client.requests.MethodCallRequestTarget`.

    Usage example:
    
    .. doctest::
    
        >>> import pyuaf
        >>> from pyuaf.client.requests import MethodCallRequestTarget, MethodCallRequestTargetVector
        >>> from pyuaf.util            import Address, ExpandedNodeId
        
        >>> # construct a vector without elements:
        >>> vec = MethodCallRequestTargetVector()
        >>> noOfElements = len(vec) # will be 0
        
        >>> vec.append(MethodCallRequestTarget())
        >>> noOfElements = len(vec) # will be 1
        >>> vec[0].objectAddress = Address(ExpandedNodeId("SomeId"     , "SomeNs", "SomeServerUri"))
        >>> vec[0].methodAddress = Address(ExpandedNodeId("SomeOtherId", "SomeNs", "SomeServerUri"))
        
        >>> vec.resize(4)
        >>> noOfElements = len(vec) # will be 4
        
        >>> # you may construct a vector from a regular Python list:
        >>> otherVec = MethodCallRequestTargetVector( [MethodCallRequestTarget(), MethodCallRequestTarget()] )
        
        >>> # or you may specify a number of targets directly
        >>> yetAnotherVec = MethodCallRequestTargetVector(3)
        >>> yetAnotherVec[0].objectAddress = Address(ExpandedNodeId("SomeId"     , "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[0].methodAddress = Address(ExpandedNodeId("SomeOtherId", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[1].objectAddress = Address(ExpandedNodeId("SomeId"     , "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[1].methodAddress = Address(ExpandedNodeId("SomeOtherId", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[2].objectAddress = Address(ExpandedNodeId("SomeId"     , "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[2].methodAddress = Address(ExpandedNodeId("SomeOtherId", "SomeNs", "SomeServerUri"))



*class* ReadRequest
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.ReadRequest

    A :class:`~pyuaf.client.requests.ReadRequest` is a synchronous request to read an attribute of 
    one or more nodes.
    
    * Methods:

        .. automethod:: pyuaf.client.requests.ReadRequest.__init__
    
            Create a new ReadRequest object.
            
            :param targets: The targets of the request, either as:
            
                             - an ``int``, specifying the number of targets (0 by default)
                             - a single target (a :class:`~pyuaf.client.requests.ReadRequestTarget`)
                             - a vector of targets (a :class:`~pyuaf.client.requests.ReadRequestTargetVector`)
    
            :param serviceConfig: The config for the service settings.
            :type serviceConfig: :class:`~pyuaf.client.configs.ReadConfig`
    
            :param sessionConfig: The config containing the session settings.
            :type sessionConfig: :class:`~pyuaf.client.configs.SessionConfig`
    
        .. method:: __str__()
    
            Get a formatted string representation of the request.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.ReadRequest.targets

            The targets, as a :class:`~pyuaf.client.requests.ReadRequestTargetVector`.
    
        .. autoattribute:: pyuaf.client.requests.ReadRequest.serviceConfig

            The service config, as a :class:`~pyuaf.client.configs.ReadConfig`.
    
        .. autoattribute:: pyuaf.client.requests.ReadRequest.sessionConfig

            The session config, as a :class:`~pyuaf.client.configs.SessionConfig`.


*class* ReadRequestTarget
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.ReadRequestTarget

    A :class:`~pyuaf.client.requests.ReadRequestTarget` is the part of 
    a :class:`~pyuaf.client.requests.ReadRequest` that specifies the target to be read.

    
    * Methods:

        .. method:: __init__(args*)
    
            Create a new ReadRequestTarget object.
            
            The default attributeId is :attr:`~pyuaf.util.attributeids.Value`.
            
            You can specify a ReadRequestTarget in three ways:
            
            .. doctest::
            
                >>> import pyuaf
                >>> from pyuaf.util                 import Address, ExpandedNodeId
                >>> from pyuaf.util.attributeids    import DisplayName
                >>> from pyuaf.client.requests      import ReadRequestTarget
                
                >>> addressOfNodeToBeRead = Address(ExpandedNodeId("someId", "someNs", "someServerUri"))
                
                >>> # there are 3 ways to define a target:
                >>> target0 = ReadRequestTarget()
                >>> target1 = ReadRequestTarget(addressOfNodeToBeRead)              # attribute id = Value
                >>> target2 = ReadRequestTarget(addressOfNodeToBeRead, DisplayName) # attribute id = DisplayName
                
                >>> # in case of the first target, you still need to specify an Address:
                >>> target0.address = addressOfNodeToBeRead
    
    
        .. method:: __str__()
    
            Get a formatted string representation of the target.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.ReadRequestTarget.address

            The address of the node of which the attribute will be read, 
            as a :class:`~pyuaf.util.Address`.
    
        .. autoattribute:: pyuaf.client.requests.ReadRequestTarget.attributeId

            The id of the attribute to be read, as an ``int`` defined 
            in :mod:`~pyuaf.util.attributeids`.
    
        .. autoattribute:: pyuaf.client.requests.ReadRequestTarget.indexRange
    
            The index range (as a ``str``), in case you want to partially read an array.



*class* ReadRequestTargetVector
----------------------------------------------------------------------------------------------------


.. class:: pyuaf.client.requests.ReadRequestTargetVector

    An ReadRequestTargetVector is a container that holds elements of type 
    :class:`pyuaf.client.requests.ReadRequestTarget`. 
    It is an artifact automatically generated from the C++ UAF code, and has the same functionality
    as a ``list`` of :class:`~pyuaf.client.requests.ReadRequestTarget`.

    Usage example:
    
    .. doctest::
    
        >>> import pyuaf
        >>> from pyuaf.client.requests import ReadRequestTarget, ReadRequestTargetVector
        >>> from pyuaf.util            import Address, ExpandedNodeId
        
        >>> # construct a vector without elements:
        >>> vec = ReadRequestTargetVector()
        >>> noOfElements = len(vec) # will be 0
        
        >>> vec.append(ReadRequestTarget())
        >>> noOfElements = len(vec) # will be 1
        >>> vec[0].address = Address(ExpandedNodeId("SomeId", "SomeNs", "SomeServerUri"))
        
        >>> vec.resize(4)
        >>> noOfElements = len(vec) # will be 4
        
        >>> # you may construct a vector from a regular Python list:
        >>> otherVec = ReadRequestTargetVector( [ReadRequestTarget(), ReadRequestTarget()] )
        
        >>> # or you may specify a number of targets directly
        >>> yetAnotherVec = ReadRequestTargetVector(3)
        >>> yetAnotherVec[0].address = Address(ExpandedNodeId("SomeId0", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[1].address = Address(ExpandedNodeId("SomeId1", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[2].address = Address(ExpandedNodeId("SomeId2", "SomeNs", "SomeServerUri"))


*class* TranslateBrowsePathsToNodeIdsRequest
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest

    A :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest` is a synchronous request 
    to translate one or more browse paths to NodeIds.
    
    * Methods:

        .. automethod:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest.__init__
    
            Create a new TranslateBrowsePathsToNodeIdsRequest object.
            
            :param targets: The targets of the request, either as:
            
                             - an ``int``, specifying the number of targets (0 by default)
                             - a single target (a :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTarget`)
                             - a vector of targets (a :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTargetVector`)
    
            :param serviceConfig: The config for the service settings.
            :type serviceConfig: :class:`~pyuaf.client.configs.TranslateBrowsePathsToNodeIdsConfig`
    
            :param sessionConfig: The config containing the session settings.
            :type sessionConfig: :class:`~pyuaf.client.configs.SessionConfig`
    
        .. method:: __str__()
    
            Get a formatted string representation of the request.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest.targets

            The targets, as a :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTargetVector`.
    
        .. autoattribute:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest.serviceConfig

            The service config, as a :class:`~pyuaf.client.configs.TranslateBrowsePathsToNodeIdsConfig`.
    
        .. autoattribute:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest.sessionConfig

            The session config, as a :class:`~pyuaf.client.configs.SessionConfig`.


*class* TranslateBrowsePathsToNodeIdsRequestTarget
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTarget

    A :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTarget` is the part of 
    a :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequest` that specifies the target 
    to be translated.

    
    * Methods:

        .. method:: __init__(args*)
    
            Create a new TranslateBrowsePathsToNodeIdsRequestTarget object.
            
            You can specify a TranslateBrowsePathsToNodeIdsRequestTarget in two ways:
            
            .. doctest::
            
                >>> import pyuaf
                >>> from pyuaf.util             import BrowsePath
                >>> from pyuaf.client.requests  import TranslateBrowsePathsToNodeIdsRequestTarget
                
                >>> browsePathToBeTranslated = BrowsePath()
                
                >>> # there are 2 ways to define a target:
                >>> target0 = TranslateBrowsePathsToNodeIdsRequestTarget()
                >>> target1 = TranslateBrowsePathsToNodeIdsRequestTarget(browsePathToBeTranslated)
                
                >>> # in case of the first target, you still need to specify a node and some data:
                >>> target0.browsePath = browsePathToBeTranslated
    
    
        .. method:: __str__()
    
            Get a formatted string representation of the target.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTarget.browsePath

            The browse path to be translated, as a :class:`~pyuaf.util.BrowsePath`.
    


*class* TranslateBrowsePathsToNodeIdsRequestTargetVector
----------------------------------------------------------------------------------------------------


.. class:: pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTargetVector

    An TranslateBrowsePathsToNodeIdsRequestTargetVector is a container that holds elements of type 
    :class:`pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTarget`. 
    It is an artifact automatically generated from the C++ UAF code, and has the same functionality
    as a ``list`` of :class:`~pyuaf.client.requests.TranslateBrowsePathsToNodeIdsRequestTarget`.

    Usage example:
    
    .. doctest::
    
        >>> import pyuaf
        >>> from pyuaf.client.requests import TranslateBrowsePathsToNodeIdsRequestTarget, \
        ...                                   TranslateBrowsePathsToNodeIdsRequestTargetVector
        >>> from pyuaf.util            import BrowsePath, ExpandedNodeId, RelativePathElement, QualifiedName
        
        >>> # construct a vector without elements:
        >>> vec = TranslateBrowsePathsToNodeIdsRequestTargetVector()
        >>> noOfElements = len(vec) # will be 0
        
        >>> # define a starting ExpandedNodeId for the browse path
        >>> startOfBrowsePath = ExpandedNodeId("SomeId", "SomeNs", "SomeServerUri")
        
        >>> vec.append(TranslateBrowsePathsToNodeIdsRequestTarget())
        >>> noOfElements = len(vec) # will be 1
        >>> vec[0].browsePath = BrowsePath(startOfBrowsePath, [RelativePathElement(QualifiedName("SomeName", "SomeNs"))] )
        
        >>> vec.resize(4)
        >>> noOfElements = len(vec) # will be 4
        
        >>> # you may construct a vector from a regular Python list:
        >>> otherVec = TranslateBrowsePathsToNodeIdsRequestTargetVector( 
        ...               [TranslateBrowsePathsToNodeIdsRequestTarget(), 
        ...                TranslateBrowsePathsToNodeIdsRequestTarget()] )
        
        >>> # or you may specify a number of targets directly
        >>> yetAnotherVec = TranslateBrowsePathsToNodeIdsRequestTargetVector(3)
        >>> yetAnotherVec[0].browsePath = BrowsePath(startOfBrowsePath, [RelativePathElement(QualifiedName("SomeName0", "SomeNs"))] )
        >>> yetAnotherVec[1].browsePath = BrowsePath(startOfBrowsePath, [RelativePathElement(QualifiedName("SomeName1", "SomeNs"))] )
        >>> yetAnotherVec[2].browsePath = BrowsePath(startOfBrowsePath, [RelativePathElement(QualifiedName("SomeName2", "SomeNs"))] )


*class* WriteRequest
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.WriteRequest

    A :class:`~pyuaf.client.requests.WriteRequest` is a synchronous request to write an attribute 
    of one or more nodes.
    
    * Methods:

        .. automethod:: pyuaf.client.requests.WriteRequest.__init__
    
            Create a new WriteRequest object.
            
            :param targets: The targets of the request, either as:
            
                             - an ``int``, specifying the number of targets (0 by default)
                             - a single target (a :class:`~pyuaf.client.requests.WriteRequestTarget`)
                             - a vector of targets (a :class:`~pyuaf.client.requests.WriteRequestTargetVector`)
    
            :param serviceConfig: The config for the service settings.
            :type serviceConfig: :class:`~pyuaf.client.configs.WriteConfig`
    
            :param sessionConfig: The config containing the session settings.
            :type sessionConfig: :class:`~pyuaf.client.configs.SessionConfig`
    
        .. method:: __str__()
    
            Get a formatted string representation of the request.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.WriteRequest.targets

            The targets, as a :class:`~pyuaf.client.requests.WriteRequestTargetVector`.
    
        .. autoattribute:: pyuaf.client.requests.WriteRequest.serviceConfig

            The service config, as a :class:`~pyuaf.client.configs.WriteConfig`.
    
        .. autoattribute:: pyuaf.client.requests.WriteRequest.sessionConfig

            The session config, as a :class:`~pyuaf.client.configs.SessionConfig`.



*class* WriteRequestTarget
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.WriteRequestTarget

    A :class:`~pyuaf.client.requests.WriteRequestTarget` is the part of 
    a :class:`~pyuaf.client.requests.WriteRequest` that specifies the target to be written.

    
    * Methods:

        .. method:: __init__(args*)
    
            Create a new WriteRequestTarget object.
            
            The default attributeId is :attr:`~pyuaf.util.attributeids.Value`.
            
            You can specify a WriteRequestTarget in three ways:
            
            .. doctest::
            
                >>> import pyuaf
                >>> from pyuaf.util                 import Address, ExpandedNodeId, LocalizedText
                >>> from pyuaf.util.attributeids    import DisplayName
                >>> from pyuaf.util.primitives      import UInt32
                >>> from pyuaf.client.requests      import WriteRequestTarget
                
                >>> addressOfNodeToBeWritten  = Address(ExpandedNodeId("someId", "someNs", "someServerUri"))
                
                >>> # there are 3 ways to define a target:
                >>> target0 = WriteRequestTarget()
                >>> target1 = WriteRequestTarget(addressOfNodeToBeWritten, UInt32(332))                                     # attribute id = Value
                >>> target2 = WriteRequestTarget(addressOfNodeToBeWritten, LocalizedText("en", "Some name"), DisplayName)   # attribute id = DisplayName
                
                >>> # in case of the first target, you still need to specify an address and some data:
                >>> target0.address = addressOfNodeToBeWritten
                >>> target0.data    = UInt32(332)
    
    
        .. method:: __str__()
    
            Get a formatted string representation of the target.


    * Attributes
    
        .. autoattribute:: pyuaf.client.requests.WriteRequestTarget.address

            The address of the node of which the attribute will be written, 
            as a :class:`~pyuaf.util.Address`.
    
        .. autoattribute:: pyuaf.client.requests.WriteRequestTarget.data

            The data to be written, as one of the data types described in :ref:`note-variants`.
    
        .. autoattribute:: pyuaf.client.requests.WriteRequestTarget.attributeId

            The attribute id to be written, as an ``int`` defined 
            in :mod:`~pyuaf.util.attributeids`.
    
        .. autoattribute:: pyuaf.client.requests.WriteRequestTarget.opcUaStatusCode

            The OPC UA status code of the data to be written, as an ``int``. Default = 0 = Good.
            
        .. autoattribute:: pyuaf.client.requests.WriteRequestTarget.indexRange
    
            The index range (as a ``str``), in case you want to partially write an array.



*class* WriteRequestTargetVector
----------------------------------------------------------------------------------------------------


.. autoclass:: pyuaf.client.requests.WriteRequestTargetVector

    An WriteRequestTargetVector is a container that holds elements of type 
    :class:`pyuaf.client.requests.WriteRequestTarget`. 
    It is an artifact automatically generated from the C++ UAF code, and has the same functionality
    as a ``list`` of :class:`~pyuaf.client.requests.WriteRequestTarget`.

    Usage example:
    
    .. doctest::
    
        >>> import pyuaf
        >>> from pyuaf.client.requests import WriteRequestTarget, WriteRequestTargetVector
        >>> from pyuaf.util            import Address, ExpandedNodeId
        >>> from pyuaf.util.primitives import UInt32, Float
        
        >>> # construct a vector without elements:
        >>> vec = WriteRequestTargetVector()
        >>> noOfElements = len(vec) # will be 0
        
        >>> vec.append(WriteRequestTarget())
        >>> noOfElements = len(vec) # will be 1
        >>> vec[0].address = Address(ExpandedNodeId("SomeId", "SomeNs", "SomeServerUri"))
        >>> vec[0].data    = UInt32(1234)
        
        >>> vec.resize(4)
        >>> noOfElements = len(vec) # will be 4
        
        >>> # you may construct a vector from a regular Python list:
        >>> otherVec = WriteRequestTargetVector( [WriteRequestTarget(), WriteRequestTarget()] )
        
        >>> # or you may specify a number of targets directly
        >>> yetAnotherVec = WriteRequestTargetVector(3)
        >>> yetAnotherVec[0].address = Address(ExpandedNodeId("SomeId0", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[0].data    = UInt32(1234)
        >>> yetAnotherVec[1].address = Address(ExpandedNodeId("SomeId1", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[1].data    = Float(0.1234)
        >>> yetAnotherVec[2].address = Address(ExpandedNodeId("SomeId2", "SomeNs", "SomeServerUri"))
        >>> yetAnotherVec[2].data    = "test"

        
        
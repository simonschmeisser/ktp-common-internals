/*
 * Global Presence - wrap Tp::Presence with KDE functionality
 *
 * Copyright (C) 2011 David Edmundson <kde@davidedmundson.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "kpresence.h"
#include <KLocalizedString>

KPresence::KPresence() :
    Tp::Presence()
{
}

KPresence::KPresence(const Tp::Presence &presence) :
    Tp::Presence(presence)
{
}

KIcon KPresence::icon() const
{
    switch (type()) {
    case Tp::ConnectionPresenceTypeAvailable:
        return KIcon(QLatin1String("user-online"));
    case Tp::ConnectionPresenceTypeBusy:
        return KIcon("user-busy");
    case Tp::ConnectionPresenceTypeAway:
        return KIcon("user-away");
    case Tp::ConnectionPresenceTypeExtendedAway:
        return KIcon("user-away-extended");
    case Tp::ConnectionPresenceTypeHidden:
        return KIcon("user-invisible");
    case Tp::ConnectionPresenceTypeOffline:
        return KIcon("user-offline");
    default:
        return KIcon();
    }
}

bool KPresence::operator <(const KPresence &other) const
{
    if (sortPriority(type()) < sortPriority(other.type())) {
        return true;
    } else if (sortPriority(type()) == sortPriority(other.type())) {
        return (statusMessage() < other.statusMessage());
    } else {
        return false;
    }
}

QString KPresence::displayString() const
{
    switch (type()) {
        case Tp::ConnectionPresenceTypeAvailable:
            return i18n("Available");
        case Tp::ConnectionPresenceTypeBusy:
            return i18n("Busy");
        case Tp::ConnectionPresenceTypeAway:
            return i18n("Away");
        case Tp::ConnectionPresenceTypeExtendedAway:
            return i18n("Not available");
        case Tp::ConnectionPresenceTypeHidden:
            return i18n("Invisible");
        case Tp::ConnectionPresenceTypeOffline:
            return i18n("Offline");
        default:
            return QString();
    }
}

int KPresence::sortPriority(const Tp::ConnectionPresenceType &type) const
{
    switch(type) {
        case Tp::ConnectionPresenceTypeAvailable:
            return 0;
        case Tp::ConnectionPresenceTypeBusy:
            return 1;
        case Tp::ConnectionPresenceTypeHidden:
            return 2;
        case Tp::ConnectionPresenceTypeAway:
            return 3;
        case Tp::ConnectionPresenceTypeExtendedAway:
            return 4;
        //don't distinguish between the following three presences
        case Tp::ConnectionPresenceTypeError:
        case Tp::ConnectionPresenceTypeUnknown:
        case Tp::ConnectionPresenceTypeUnset:
            return 5;
        case Tp::ConnectionPresenceTypeOffline:
        default:
            return 6;
    }

    return -1;
}
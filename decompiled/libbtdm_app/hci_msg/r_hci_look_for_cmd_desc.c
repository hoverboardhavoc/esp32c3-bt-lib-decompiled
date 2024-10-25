/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> hci_msg.o -> r_hci_look_for_cmd_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * r_hci_look_for_cmd_desc(uint param_1)

{
  byte *pbVar1;
  short sVar2;
  int iVar3;
  ushort *puVar4;
  
  pbVar1 = &hci_cmd_desc_root_tab;
  iVar3 = 0;
  do {
    if ((uint)*pbVar1 == param_1 >> 10) {
      puVar4 = *(ushort **)(iVar3 * 8 + 0x12014);
      sVar2 = 0;
      if (puVar4 != (ushort *)0x0) {
        for (; sVar2 != *(short *)(&DAT_00012012 + iVar3 * 8); sVar2 = sVar2 + 1) {
          if ((*puVar4 & 0x3ff) == (param_1 & 0x3ff)) {
            return puVar4;
          }
          puVar4 = puVar4 + 6;
        }
      }
      break;
    }
    iVar3 = iVar3 + 1;
    pbVar1 = pbVar1 + 8;
  } while (iVar3 != 6);
  puVar4 = (ushort *)0x0;
  if ((0xfc80 < param_1) && (puVar4 = _esp_vendor_cmd, _esp_vendor_cmd != (ushort *)0x0)) {
    for (sVar2 = 0; _memcpy != sVar2; sVar2 = sVar2 + 1) {
      if ((*puVar4 & 0x3ff) == (param_1 & 0x3ff)) {
        return puVar4;
      }
      puVar4 = puVar4 + 6;
    }
    puVar4 = (ushort *)0x0;
  }
  return puVar4;
}


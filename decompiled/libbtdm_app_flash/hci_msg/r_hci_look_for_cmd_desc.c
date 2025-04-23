/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_msg.o -> r_hci_look_for_cmd_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * r_hci_look_for_cmd_desc(uint param_1)

{
  ushort *puVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  
  uVar2 = param_1 >> 10;
  if (uVar2 == 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
    if (uVar2 != 3) {
      if (uVar2 == 4) {
        iVar4 = 2;
      }
      else {
        iVar4 = 3;
        if ((uVar2 != 5) && (iVar4 = 4, uVar2 != 8)) {
          if (uVar2 != 0x3f) {
            return (ushort *)0x0;
          }
          iVar4 = 5;
        }
      }
    }
  }
  puVar1 = *(ushort **)(hci_cmd_desc_root_tab_flash + iVar4 * 8 + 4);
  sVar3 = 0;
  if (puVar1 != (ushort *)0x0) {
    for (; sVar3 != *(short *)(hci_cmd_desc_root_tab_flash + iVar4 * 8 + 2); sVar3 = sVar3 + 1) {
      if ((param_1 & 0x3ff) == (*puVar1 & 0x3ff)) {
        return puVar1;
      }
      puVar1 = puVar1 + 6;
    }
  }
  puVar1 = (ushort *)0x0;
  if ((0xfc80 < param_1) && (puVar1 = _esp_vendor_cmd, _esp_vendor_cmd != (ushort *)0x0)) {
    for (sVar3 = 0; _memcpy != sVar3; sVar3 = sVar3 + 1) {
      if ((param_1 & 0x3ff) == (*puVar1 & 0x3ff)) {
        return puVar1;
      }
      puVar1 = puVar1 + 6;
    }
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}


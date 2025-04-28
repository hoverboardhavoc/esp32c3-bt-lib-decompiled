/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  short sVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 >> 10;
  if (uVar3 == 1) {
    iVar4 = 0;
  }
  else if (uVar3 == 3) {
    iVar4 = 1;
  }
  else if (uVar3 == 4) {
    iVar4 = 2;
  }
  else if (uVar3 == 5) {
    iVar4 = 3;
  }
  else if (uVar3 == 8) {
    iVar4 = 4;
  }
  else {
    if (uVar3 != 0x3f) goto _L130;
    iVar4 = 5;
  }
  puVar1 = *(ushort **)(hci_cmd_desc_root_tab_flash + iVar4 * 8 + 4);
  sVar2 = 0;
  if (puVar1 != (ushort *)0x0) {
    for (; sVar2 != *(short *)(hci_cmd_desc_root_tab_flash + iVar4 * 8 + 2); sVar2 = sVar2 + 1) {
      if ((*puVar1 & 0x3ff) == (param_1 & 0x3ff)) {
        return puVar1;
      }
      puVar1 = puVar1 + 6;
    }
  }
_L130:
  puVar1 = (ushort *)0x0;
  if ((0xfc80 < param_1) && (puVar1 = _esp_vendor_cmd, _esp_vendor_cmd != (ushort *)0x0)) {
    for (sVar2 = 0; _memcpy != sVar2; sVar2 = sVar2 + 1) {
      if ((*puVar1 & 0x3ff) == (param_1 & 0x3ff)) {
        return puVar1;
      }
      puVar1 = puVar1 + 6;
    }
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}


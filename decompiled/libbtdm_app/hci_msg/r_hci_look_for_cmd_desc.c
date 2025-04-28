/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci_msg.o -> r_hci_look_for_cmd_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * r_hci_look_for_cmd_desc(uint param_1)

{
  ushort *puVar1;
  byte *pbVar2;
  int iVar3;
  short sVar4;
  
  pbVar2 = &hci_cmd_desc_root_tab;
  iVar3 = 0;
  do {
    if ((uint)*pbVar2 == param_1 >> 10) {
      puVar1 = *(ushort **)(iVar3 * 8 + 0x12014);
      sVar4 = 0;
      if (puVar1 != (ushort *)0x0) {
        for (; sVar4 != *(short *)(&DAT_00012012 + iVar3 * 8); sVar4 = sVar4 + 1) {
          if ((*puVar1 & 0x3ff) == (param_1 & 0x3ff)) {
            return puVar1;
          }
          puVar1 = puVar1 + 6;
        }
      }
      break;
    }
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 8;
  } while (iVar3 != 6);
  puVar1 = (ushort *)0x0;
  if ((0xfc80 < param_1) && (puVar1 = _esp_vendor_cmd, _esp_vendor_cmd != (ushort *)0x0)) {
    for (sVar4 = 0; _memcpy != sVar4; sVar4 = sVar4 + 1) {
      if ((*puVar1 & 0x3ff) == (param_1 & 0x3ff)) {
        return puVar1;
      }
      puVar1 = puVar1 + 6;
    }
    puVar1 = (ushort *)0x0;
  }
  return puVar1;
}


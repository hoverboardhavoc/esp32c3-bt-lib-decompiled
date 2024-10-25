/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> hci_msg.o -> r_hci_look_for_cmd_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * r_hci_look_for_cmd_desc(uint param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  
  uVar2 = param_1 >> 10;
  if (uVar2 == 1) {
    iVar3 = 0;
  }
  else if (uVar2 == 3) {
    iVar3 = 1;
  }
  else if (uVar2 == 4) {
    iVar3 = 2;
  }
  else if (uVar2 == 5) {
    iVar3 = 3;
  }
  else if (uVar2 == 8) {
    iVar3 = 4;
  }
  else {
    if (uVar2 != 0x3f) {
      return (ushort *)0x0;
    }
    iVar3 = 5;
  }
  puVar4 = *(ushort **)(hci_cmd_desc_root_tab_flash + iVar3 * 8 + 4);
  sVar1 = 0;
  if (puVar4 != (ushort *)0x0) {
    for (; sVar1 != *(short *)(hci_cmd_desc_root_tab_flash + iVar3 * 8 + 2); sVar1 = sVar1 + 1) {
      if ((*puVar4 & 0x3ff) == (param_1 & 0x3ff)) {
        return puVar4;
      }
      puVar4 = puVar4 + 6;
    }
  }
  puVar4 = (ushort *)0x0;
  if ((0xfc80 < param_1) && (puVar4 = _esp_vendor_cmd, _esp_vendor_cmd != (ushort *)0x0)) {
    for (sVar1 = 0; _memcpy != sVar1; sVar1 = sVar1 + 1) {
      if ((*puVar4 & 0x3ff) == (param_1 & 0x3ff)) {
        return puVar4;
      }
      puVar4 = puVar4 + 6;
    }
    puVar4 = (ushort *)0x0;
  }
  return puVar4;
}


/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> hci_tl.o -> r_hci_build_le_evt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_hci_build_le_evt(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ushort auStack_22 [7];
  
  auStack_22[0] = *(ushort *)(param_1 + 10);
  bVar1 = *(byte *)(param_1 + 0xc);
  if (bVar1 < 0xf0) {
    iVar2 = r_hci_look_for_le_evt_desc(bVar1);
  }
  else {
    iVar2 = r_hci_look_for_le_evt_desc_esp();
  }
  if (iVar2 == 0) {
    r_assert_param(bVar1,0,"hci_tl.c",0x2f8);
    return param_1 + 10;
  }
  if (*(code **)(iVar2 + 4) == (code *)0x0) {
    uVar3 = 4;
  }
  else {
    if (*(char *)(iVar2 + 2) == '\0') {
      uVar3 = r_co_util_pack();
    }
    else {
      uVar3 = (**(code **)(iVar2 + 4))(param_1 + 0xc,auStack_22,auStack_22[0]);
      uVar3 = uVar3 & 0xff;
    }
    if (uVar3 == 0) goto _L96;
  }
  r_assert_param(uVar3,bVar1,"hci_tl.c",0x2eb);
_L96:
  if (*(ushort *)(param_1 + 10) < auStack_22[0]) {
    r_assert_param(bVar1,"hci_tl.c",0x2ec);
  }
  if (uVar3 == 0) {
    *(undefined1 *)(param_1 + 10) = 0x3e;
    *(char *)(param_1 + 0xb) = (char)auStack_22[0];
  }
  return param_1 + 10;
}


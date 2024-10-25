/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
    if (uVar3 == 0) goto _L102;
  }
  r_assert_param(uVar3,bVar1,"hci_tl.c",0x2eb);
_L102:
  if (*(ushort *)(param_1 + 10) < auStack_22[0]) {
    r_assert_param(bVar1,"hci_tl.c",0x2ec);
  }
  if (uVar3 == 0) {
    *(undefined1 *)(param_1 + 10) = 0x3e;
    *(char *)(param_1 + 0xb) = (char)auStack_22[0];
  }
  return param_1 + 10;
}


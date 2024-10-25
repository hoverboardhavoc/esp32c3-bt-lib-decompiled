/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llm_hci.o -> hci_le_rand_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_rand_cmd_handler(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined1 *)r_ke_msg_alloc(0x1101,0,0x2018,9);
  uVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  puVar2[2] = (char)((uint)uVar3 >> 8);
  puVar2[1] = (char)uVar3;
  puVar2[3] = (char)((uint)uVar3 >> 0x10);
  iVar1 = _r_osi_funcs_p;
  puVar2[4] = (char)((uint)uVar3 >> 0x18);
  uVar3 = (**(code **)(iVar1 + 0x88))(*(code **)(iVar1 + 0x88));
  puVar2[5] = (char)uVar3;
  puVar2[6] = (char)((uint)uVar3 >> 8);
  puVar2[8] = (char)((uint)uVar3 >> 0x18);
  puVar2[7] = (char)((uint)uVar3 >> 0x10);
  *puVar2 = 0;
  r_hci_send_2_host(puVar2);
  return 0;
}


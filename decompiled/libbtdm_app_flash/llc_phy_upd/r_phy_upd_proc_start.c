/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> r_phy_upd_proc_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_phy_upd_proc_start(int param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
  *(undefined1 *)(puVar2 + 1) = 9;
  r_llc_proc_state_set(param_1,0);
  *puVar2 = r_llc_loc_phy_upd_proc_err_cb;
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  *(undefined1 *)((int)puVar2 + 0xb) = *(undefined1 *)(iVar3 + 0x27);
  uVar1 = *(undefined1 *)(iVar3 + 0x26);
  *(undefined2 *)(puVar2 + 4) = 0;
  *(undefined1 *)((int)puVar2 + 0xe) = 0;
  *(undefined1 *)((int)puVar2 + 10) = uVar1;
  r_ke_msg_send(puVar2);
  return;
}


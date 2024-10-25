/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> f_ll_phy_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int f_ll_phy_req_handler(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  iVar3 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = r_llc_proc_id_get(1);
  if (iVar4 == 0) {
    iVar4 = 0x1e;
    if (((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) &&
       (((*(ushort *)(iVar3 + 0x42) & 1) == 0 ||
        (iVar4 = r_llc_proc_collision_check(param_1,9), iVar4 == 0)))) {
      puVar5 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
      *(undefined1 *)(puVar5 + 1) = 9;
      r_llc_proc_state_set(param_1,5);
      *puVar5 = r_llc_rem_phy_upd_proc_err_cb;
      bVar1 = *(byte *)(param_2 + 1);
      *(byte *)((int)puVar5 + 0xb) = bVar1;
      bVar2 = *(byte *)(param_2 + 2);
      *(byte *)((int)puVar5 + 10) = bVar2;
      if ((uint)bVar1 == (uint)bVar2) {
        bVar6 = (&one_bits)[bVar1] == '\x01';
      }
      else {
        bVar6 = false;
      }
      *(bool *)((int)puVar5 + 0xf) = bVar6;
      r_llc_proc_reg(param_1,1,puVar5);
      r_llc_rem_phy_upd_proc_continue_eco(param_1,5,0);
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 0x24;
  }
  return iVar4;
}


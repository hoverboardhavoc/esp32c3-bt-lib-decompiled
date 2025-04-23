/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_phy_upd.o -> ll_phy_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ll_phy_req_handler(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  
  iVar4 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar4 + 0x18) == '\0') {
    return 0x24;
  }
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llc_proc_id_get(1,param_3);
  if (iVar2 == 0) {
    iVar2 = 0x1e;
    if (((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) &&
       (((*(ushort *)(iVar4 + 0x42) & 1) == 0 ||
        (iVar2 = r_llc_proc_collision_check(param_1,9), iVar2 == 0)))) {
      puVar3 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
      *(undefined1 *)(puVar3 + 1) = 9;
      r_llc_proc_state_set(param_1,5);
      *puVar3 = r_llc_rem_phy_upd_proc_err_cb;
      bVar5 = *(byte *)(param_2 + 1);
      *(byte *)((int)puVar3 + 0xb) = bVar5;
      bVar1 = *(byte *)(param_2 + 2);
      *(byte *)((int)puVar3 + 10) = bVar1;
      if ((uint)bVar5 == (uint)bVar1) {
        bVar5 = (&one_bits)[bVar5] & -((&one_bits)[bVar5] == 1);
      }
      else {
        bVar5 = 0;
      }
      *(byte *)((int)puVar3 + 0xf) = bVar5 & 1;
      r_llc_proc_reg(param_1,1,puVar3);
      r_llc_rem_phy_upd_proc_continue_eco(param_1,5,0);
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0x24;
  }
  return iVar2;
}


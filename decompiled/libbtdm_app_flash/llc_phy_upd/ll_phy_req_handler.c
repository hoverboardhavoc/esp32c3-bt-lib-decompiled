/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
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
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar5 + 0x18) == '\0') {
    return 0x24;
  }
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = r_llc_proc_id_get(1,param_3);
  if (iVar3 == 0) {
    iVar3 = 0x1e;
    if (((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) &&
       (((*(ushort *)(iVar5 + 0x42) & 1) == 0 ||
        (iVar3 = r_llc_proc_collision_check(param_1,9), iVar3 == 0)))) {
      puVar4 = (undefined4 *)r_ke_msg_alloc(0x10e,param_1 << 8 | 1,0x14);
      *(undefined1 *)(puVar4 + 1) = 9;
      r_llc_proc_state_set(param_1,5);
      *puVar4 = r_llc_rem_phy_upd_proc_err_cb;
      bVar1 = *(byte *)(param_2 + 1);
      *(byte *)((int)puVar4 + 0xb) = bVar1;
      bVar2 = *(byte *)(param_2 + 2);
      *(byte *)((int)puVar4 + 10) = bVar2;
      if ((uint)bVar1 == (uint)bVar2) {
        bVar6 = (&one_bits)[bVar1] == '\x01';
      }
      else {
        bVar6 = false;
      }
      *(bool *)((int)puVar4 + 0xf) = bVar6;
      r_llc_proc_reg(param_1,1,puVar4);
      r_llc_rem_phy_upd_proc_continue_eco(param_1,5,0);
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0x24;
  }
  return iVar3;
}


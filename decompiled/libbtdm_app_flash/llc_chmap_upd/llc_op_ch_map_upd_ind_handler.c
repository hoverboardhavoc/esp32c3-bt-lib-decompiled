/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app_flash -> llc_chmap_upd.o -> llc_op_ch_map_upd_ind_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 llc_op_ch_map_upd_ind_handler(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_2 = param_2 >> 8;
  iVar3 = *(int *)(&llc_env + param_2 * 4);
  iVar1 = r_sdk_config_get_opts();
  uVar2 = 0;
  if (((param_2 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_2 * 4), iVar1 != 0))
     && ((*(byte *)(iVar1 + 0x44) & 3) != 3)) {
    iVar1 = r_llc_proc_id_get(param_2,0);
    uVar2 = 2;
    if ((iVar1 == 0) && ((*(ushort *)(iVar3 + 0x42) & 0x10) == 0)) {
      r_llc_proc_reg(param_2,0,param_1);
      r_llc_loc_ch_map_proc_continue_hack(param_2,0,0);
      uVar2 = 1;
    }
  }
  return uVar2;
}


/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_start_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_start_hack(int param_1,undefined4 param_2)

{
  int iVar1;
  
  g_last_clock = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  *(undefined2 *)(con_sync_err_cnt + param_1 * 2) = 0;
  lld_con_update_terminte_info_init(param_1);
  iVar1 = r_lld_con_start(param_1,param_2);
  if (iVar1 == 0) {
    *(undefined2 *)(*(int *)(&lld_con_env + param_1 * 4) + 0x98) = 0xffff;
  }
  return;
}


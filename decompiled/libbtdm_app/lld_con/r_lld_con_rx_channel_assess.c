/*
 * Last changed at upstream commit d53a6a695af1e78a6f36691e2cf525f9787abfdb
 * https://github.com/espressif/esp32c3-bt-lib/commit/d53a6a695af1e78a6f36691e2cf525f9787abfdb
 * Upstream date: 2024-07-11 12:21:12 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(abd7733)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx_channel_assess
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_channel_assess(int param_1,int param_2)

{
  byte bVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar5 = (uint)*(ushort *)(iVar4 + (uint)bVar1 * 0x14 + 6);
  if ((*(ushort *)(param_1 + 0x84) & 0x100) != 0) {
    uVar2 = (*_rwip_rf)(uVar5 & 0xff,uVar3,_rwip_rf);
    *(undefined1 *)(param_1 + 0x95) = uVar2;
  }
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x95) <= sdk_cfg_priv_opts) {
      return;
    }
    uVar6 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x228);
  }
  else {
    uVar6 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x228);
  }
                    /* WARNING: Could not recover jumptable at 0x0001138e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((int)uVar5 >> 8 & 0x3f,uVar6,uVar3);
  return;
}


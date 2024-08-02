/*
 * Last changed at upstream commit 929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * https://github.com/espressif/esp32c3-bt-lib/commit/929c19d35d3c2c5568206f22d077d2d3ee9f1883
 * Upstream date: 2024-08-02 17:03:33 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(b445b5f)
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
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = (uint)*(ushort *)((uint)bVar1 * 0x14 + 6 + iVar4);
  iVar4 = (*_rwip_rf)(uVar2 & 0xff,_rwip_rf);
  if ((*(ushort *)(param_1 + 0x84) & 0x100) != 0) {
    *(char *)(param_1 + 0x95) = (char)iVar4;
  }
  if (param_2 == 0) {
    if (iVar4 <= sdk_cfg_priv_opts) {
      return;
    }
    uVar5 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x228);
  }
  else {
    uVar5 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x228);
  }
                    /* WARNING: Could not recover jumptable at 0x000113d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((int)uVar2 >> 8 & 0x3f,uVar5,uVar3);
  return;
}


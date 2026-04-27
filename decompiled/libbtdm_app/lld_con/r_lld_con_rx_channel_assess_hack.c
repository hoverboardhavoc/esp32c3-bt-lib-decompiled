/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx_channel_assess_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_channel_assess_hack(int param_1,int param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar2 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = (uint)*(ushort *)((uint)bVar1 * 0x14 + 6 + iVar3);
  iVar3 = (*_co_sca2ppm)(uVar4 & 0xff,_co_sca2ppm);
  if ((*(ushort *)(param_1 + 0x84) & 0x100) != 0) {
    *(char *)(param_1 + 0x95) = (char)iVar3;
  }
  if (param_2 == 0) {
    if (iVar3 <= sdk_cfg_priv_opts) {
      return;
    }
    uVar5 = 0;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x228);
  }
  else {
    uVar5 = 1;
    UNRECOVERED_JUMPTABLE = *(code **)(_r_ip_funcs_p + 0x228);
  }
                    /* WARNING: Could not recover jumptable at 0x00011950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)((int)uVar4 >> 8 & 0x3f,uVar5,uVar2,UNRECOVERED_JUMPTABLE);
  return;
}


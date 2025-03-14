/*
 * Last changed at upstream commit bc9fd38197fb6a50e1b09791498782a1797e4757
 * https://github.com/espressif/esp32c3-bt-lib/commit/bc9fd38197fb6a50e1b09791498782a1797e4757
 * Upstream date: 2025-03-14 10:49:41 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(99e9a8dd)
 * Source: libbtdm_app -> llc_encrypt.o -> f_ll_pause_enc_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_pause_enc_rsp_handler(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if ((*(ushort *)(iVar4 + 0x42) & 1) != 0) {
    iVar1 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678));
    if (iVar1 == 3) {
      uVar2 = 1;
      pcVar3 = *(code **)(_r_ip_funcs_p + 0x594);
      goto _L149;
    }
    if ((*(ushort *)(iVar4 + 0x42) & 1) != 0) {
      return 0x24;
    }
  }
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x678))(param_1,1,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar4 != 3) {
    return 0x24;
  }
  uVar2 = 0xb;
  pcVar3 = *(code **)(_r_ip_funcs_p + 0x59c);
_L149:
  (*pcVar3)(param_1,uVar2,0,pcVar3);
  return 0;
}


/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_tx_cal_con_timestamp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_lld_init_process_pkt_tx_cal_con_timestamp(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = _lld_init_env;
  bVar1 = (&co_rate_to_phy)[*(byte *)(_lld_init_env + 0x4e)];
  bVar2 = *(byte *)(*(int *)(param_1 * 4 + _lld_init_env) + 0x52);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = *(int *)(iVar4 + 0x54);
  uVar7 = (uint)*(ushort *)((uint)bVar2 * 0x5a + 0x44 + iVar5) << 2;
  if (sdk_cfg_priv_opts != '\0') {
    iVar5 = 1;
    if (*(char *)(iVar4 + 0x59) != '\0') {
      iVar5 = (1 < *(byte *)(iVar4 + 0x4e)) + 2;
    }
                    /* WARNING: Could not recover jumptable at 0x00010f7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar7 = (**(code **)(_r_ip_funcs_p + 0x46c))
                      (iVar6,uVar7,iVar5 << 2,*(code **)(_r_ip_funcs_p + 0x46c));
    return uVar7;
  }
  iVar4 = iVar4 + (uint)bVar1 * 10;
  uVar3 = *(ushort *)(iVar4 + 4);
  uVar8 = (uint)*(ushort *)(iVar4 + 2) * 4;
  if (*(ushort *)(iVar4 + 2) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar8 = (uVar8 + iVar6) - (iVar6 + (uint)uVar3 * -2 & 0xfffffff) % uVar8 & 0xfffffff;
  if ((uVar8 - iVar6 & 0xfffffff) < uVar7) {
    uVar8 = uVar8 + (uint)*(ushort *)(iVar4 + 2) * 4 & 0xfffffff;
  }
  return uVar8;
}


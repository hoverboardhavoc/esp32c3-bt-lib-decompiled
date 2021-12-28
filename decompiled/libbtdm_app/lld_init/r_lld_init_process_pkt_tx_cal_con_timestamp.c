/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
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
  
  iVar4 = lld_init_env;
  bVar1 = (&co_rate_to_phy)[*(byte *)(lld_init_env + 0x4e)];
  bVar2 = *(byte *)(*(int *)(param_1 * 4 + lld_init_env) + 0x52);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = *(int *)(iVar4 + 0x54);
  uVar8 = (uint)*(ushort *)(iVar5 + (uint)bVar2 * 0x5a + 0x44) << 2;
  if (sdk_cfg_priv_opts != '\0') {
    iVar5 = 1;
    if (*(char *)(iVar4 + 0x59) != '\0') {
      iVar5 = (1 < *(byte *)(iVar4 + 0x4e)) + 2;
    }
                    /* WARNING: Could not recover jumptable at 0x00012254. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar8 = (**(code **)(_r_ip_funcs_p + 0x46c))(iVar6,uVar8,iVar5 << 2);
    return uVar8;
  }
  iVar4 = iVar4 + (uint)bVar1 * 10;
  uVar3 = *(ushort *)(iVar4 + 4);
  uVar7 = (uint)*(ushort *)(iVar4 + 2) * 4;
  if (*(ushort *)(iVar4 + 2) == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x94,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar7 = (uVar7 + iVar6) - (iVar6 + (uint)uVar3 * -2 & 0xfffffff) % uVar7 & 0xfffffff;
  if ((uVar7 - iVar6 & 0xfffffff) < uVar8) {
    uVar7 = uVar7 + (uint)*(ushort *)(iVar4 + 2) * 4 & 0xfffffff;
  }
  return uVar7;
}


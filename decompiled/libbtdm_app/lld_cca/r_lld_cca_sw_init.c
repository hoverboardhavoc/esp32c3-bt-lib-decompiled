/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_sw_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_sw_init(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  iVar4 = _r_ip_funcs_p;
  puVar1 = p_lld_cca;
  if ((*(byte *)((int)p_lld_cca + 6) & 1) == 0) {
    *(byte *)((int)p_lld_cca + 6) = *(byte *)((int)p_lld_cca + 6) | 1;
    *puVar1 = *(undefined4 *)(iVar4 + 0x9d4);
    pcVar5 = *(code **)(iVar4 + 0x4ec);
    uVar3 = (*pcVar5)(pcVar5);
    puVar2 = p_lld_cca;
    puVar1[7] = uVar3;
    pbVar6 = (byte *)puVar2[10];
    pbVar7 = pbVar6;
    do {
      pbVar8 = pbVar7 + 0xc;
      *pbVar7 = *pbVar7 | 1;
      pbVar7 = pbVar8;
    } while (pbVar8 != pbVar6 + 0x1e0);
    *(undefined2 *)((int)puVar2 + 0x12) = 0x640;
    pcVar5 = *(code **)(_r_ip_funcs_p + 0x94c);
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    (*pcVar5)(0xc,*(undefined1 *)(iVar4 + 0x12),3,0,0);
    _DAT_600110d4 = _DAT_600110d4 & 0xfe1fffff;
    (**(code **)(_r_ip_funcs_p + 0x11c))(1,*(code **)(_r_ip_funcs_p + 0x11c));
    bt_bb_tx_cca_set(1,0,0,0,0,0,0,0);
                    /* WARNING: Could not recover jumptable at 0x000110b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 0xe4))(0,0,0,*(code **)(_r_plf_funcs_p + 0xe4));
    return;
  }
  return;
}


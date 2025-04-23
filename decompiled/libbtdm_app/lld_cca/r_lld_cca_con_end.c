/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_cca.o -> r_lld_cca_con_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_cca_con_end(void)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  sVar2 = *(short *)(p_lld_cca + 0x16);
  pbVar5 = (byte *)(*(int *)(p_lld_cca + 0x28) + (uint)*(byte *)(p_lld_cca + 8) * 0xc);
  if (sVar2 != 0) {
    bVar1 = *(byte *)(p_lld_cca + 0xd);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = p_lld_cca;
    *(short *)((uint)bVar1 * 0x5a + 0x20 + iVar6) = sVar2;
    *(undefined2 *)(iVar4 + 0x16) = 0;
  }
  if ((*pbVar5 & 0x10) != 0) {
    (**(code **)(_r_ip_funcs_p + 0x978))(0,*(code **)(_r_ip_funcs_p + 0x978));
    *pbVar5 = *pbVar5 & 0xef;
  }
  uVar3 = *(ushort *)(p_lld_cca + 4);
  if ((uVar3 & 0x10) == 0) {
    if (((uVar3 & 2) == 0) || ((*pbVar5 & 0x20) == 0)) {
      if ((*pbVar5 & 8) == 0) {
        if ((uVar3 & 1) != 0) {
          (**(code **)(_r_ip_funcs_p + 0x998))(pbVar5,*(code **)(_r_ip_funcs_p + 0x998));
        }
        if ((*pbVar5 & 2) != 0) {
          *pbVar5 = *pbVar5 & 0xfe | 8;
          pbVar5[8] = pbVar5[8] + 1;
        }
        if ((*(ushort *)(p_lld_cca + 4) & 4) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00010ea4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**(code **)(_r_ip_funcs_p + 0x9a0))(pbVar5,*(code **)(_r_ip_funcs_p + 0x9a0));
          return;
        }
      }
    }
    else {
      (**(code **)(_r_ip_funcs_p + 0x97c))(0,*(code **)(_r_ip_funcs_p + 0x97c));
      *pbVar5 = *pbVar5 & 0xdf;
    }
  }
  return;
}


/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_chain_construct(int param_1)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  short sStack_46;
  undefined2 uStack_44;
  short sStack_42;
  
  iVar3 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uStack_44 = 0;
  sStack_42 = 0;
  uVar4 = (uint)*(byte *)(iVar3 + 0x52) * 9 & 0xff;
  sStack_46 = (ushort)*(byte *)(iVar3 + 0x52) * 0x4b + 0x2000;
  uVar5 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
  uStack_44 = *(undefined2 *)(iVar3 + 0x4e);
  *(undefined2 *)(iVar3 + 0x4a) = 0;
  *(undefined1 *)(iVar3 + 0x57) = uVar5;
  sStack_42 = *(short *)(iVar3 + 0x50);
  *(undefined4 *)(iVar3 + 0x44) = 0;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x2e8))
                    (param_1,uVar4,7,0,*(uint *)(iVar3 + 0x48) >> 6 & 1,0,&sStack_46,&uStack_44);
  bVar8 = *(byte *)(iVar3 + 0x57);
  *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + iVar6;
  if ((bVar8 & 0xc0) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar9 = param_1 * 0x5a;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar6 + iVar9 + 0x26);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar6 + iVar9 + 0x26) = uVar1 & 0x3ff | (ushort)bVar8 << 10;
  bVar8 = *(byte *)(iVar3 + 0x55);
  if ((bVar8 & 0xfc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x1bf,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar1 = *(ushort *)(iVar6 + iVar9 + 4);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar6 = _r_plf_funcs_p;
  *(ushort *)(iVar7 + iVar9 + 4) = uVar1 & 0xffcf | (ushort)bVar8 << 4;
  iVar6 = (**(code **)(iVar6 + 0xbc))(0x400,*(code **)(iVar6 + 0xbc));
  cVar2 = '\0';
  *(short *)(iVar9 + 0x34 + iVar6) = (short)uVar4 * 0xe + 0x1400;
  while( true ) {
    cVar2 = cVar2 + '\x01';
    if (sStack_42 == 0) break;
    bVar8 = *(char *)(iVar3 + 0x52) * '\t' + cVar2;
    iVar6 = (**(code **)(_r_ip_funcs_p + 0x2e8))
                      (param_1,(uint)bVar8,7,0,*(uint *)(iVar3 + 0x48) >> 6 & 1,0,&sStack_46,
                       &uStack_44);
    *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + iVar6;
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(ushort *)(iVar6 + uVar4 * 0xe);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(uVar4 * 0xe + iVar6) = (ushort)bVar8 * 0xe + 0x1400 | uVar1 & 0x8000;
    uVar4 = (uint)bVar8;
  }
  uVar4 = (uint)_sdk_cfg_priv_opts;
  *(char *)(iVar3 + 0x58) = cVar2;
  uVar4 = *(int *)(iVar3 + 0x44) * 2 + uVar4;
  if (uVar4 < 0x272) {
    uVar4 = 0x272;
  }
  *(uint *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x10) = uVar4;
  return;
}


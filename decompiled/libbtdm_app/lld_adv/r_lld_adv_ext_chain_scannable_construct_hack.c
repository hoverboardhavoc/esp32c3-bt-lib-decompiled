/*
 * Last changed at upstream commit 86145c184578f9061d2d0efb30fefa20a91a75e9
 * https://github.com/espressif/esp32c3-bt-lib/commit/86145c184578f9061d2d0efb30fefa20a91a75e9
 * Upstream date: 2021-12-17 19:26:32 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(68818697)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_scannable_construct_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_scannable_construct_hack(int param_1)

{
  short sVar1;
  byte bVar2;
  int iVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar4 = *(ushort *)(iVar3 + 0x74) & 3;
  uVar8 = ((uint)*(byte *)(iVar3 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,uVar4,0,0,1,1);
  iVar6 = _r_ip_funcs_p;
  *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
  iVar6 = (**(code **)(iVar6 + 0x1b0))
                    (param_1,uVar8,7,uVar4,1,*(ushort *)(iVar3 + 0x74) >> 2 & 1,1,0);
  uVar9 = (uint)*(byte *)(iVar3 + 0x91) << 10;
  *(int *)(iVar3 + 0x6c) = iVar6 + *(int *)(iVar3 + 0x6c);
  if ((uVar9 & 0x30000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = param_1 * 0x5a;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar5 + iVar6 + 0x26);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar7 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar5 + iVar6 + 0x26) = uVar4 & 0x3ff | (ushort)uVar9;
  iVar5 = (*pcVar7)(0x400,pcVar7);
  uVar4 = *(ushort *)(iVar5 + iVar6 + 4);
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + iVar6 + 4) = uVar4 & 0xffcf | 0x10;
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar6 + 0x34 + iVar5) = (short)uVar8 * 0xe + 0x1400;
  cVar10 = *(char *)(iVar3 + 0x90);
  if (cVar10 == '\x03') {
    cVar10 = '\x02';
  }
  iVar6 = (**(code **)(_r_modules_funcs_p + 4))(0xc,cVar10,*(code **)(_r_modules_funcs_p + 4));
  *(int *)(iVar3 + 0x6c) = *(int *)(iVar3 + 0x6c) + iVar6 + 0x96;
  sVar1 = *(short *)(iVar3 + 0x84);
  uVar9 = (uint)*(byte *)(iVar3 + 0x87) * 9 + 2 & 0xff;
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar4 = *(ushort *)(iVar6 + uVar8 * 0xe);
  iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(uVar8 * 0xe + iVar6) = (short)uVar9 * 0xe + 0x1400U | uVar4 & 0x8000;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,uVar9,7,0,1,0,0,0);
  cVar10 = '\x02';
  *(int *)(iVar3 + 0x6c) = iVar6 + *(int *)(iVar3 + 0x6c);
  while (cVar10 = cVar10 + '\x01', sVar1 != 0) {
    bVar2 = *(char *)(iVar3 + 0x87) * '\t' + cVar10;
    iVar5 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,(uint)bVar2,7,0,0,0,0,0);
    iVar6 = _r_plf_funcs_p;
    *(int *)(iVar3 + 0x6c) = iVar5 + *(int *)(iVar3 + 0x6c);
    iVar6 = (**(code **)(iVar6 + 0xbc))(0x1400,*(code **)(iVar6 + 0xbc));
    uVar4 = *(ushort *)(iVar6 + uVar9 * 0xe);
    iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
    *(ushort *)(iVar6 + uVar9 * 0xe) = (ushort)bVar2 * 0xe + 0x1400 | uVar4 & 0x8000;
    uVar9 = (uint)bVar2;
  }
  *(char *)(iVar3 + 0x92) = cVar10;
  return;
}


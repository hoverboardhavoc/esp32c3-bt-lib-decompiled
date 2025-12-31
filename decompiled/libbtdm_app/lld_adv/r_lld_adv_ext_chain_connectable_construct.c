/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_ext_chain_connectable_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_connectable_construct(int param_1)

{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  code *pcVar9;
  uint uVar10;
  
  iVar4 = *(int *)(&lld_adv_env + param_1 * 4);
  uVar2 = *(ushort *)(iVar4 + 0x74);
  uVar5 = ((uint)*(byte *)(iVar4 + 0x87) * 9 & 0xff) + 1 & 0xff;
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,7,0,0,1,1);
  iVar7 = _r_ip_funcs_p;
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar6;
  sVar3 = *(short *)(iVar4 + 0x82);
  iVar7 = (**(code **)(iVar7 + 0x1b0))
                    (param_1,uVar5,7,uVar2 & 3,1,*(ushort *)(iVar4 + 0x74) >> 2 & 1,1,0);
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7;
  if (sVar3 != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x65b,*(code **)(_r_plf_funcs_p + 8));
  }
  uVar10 = (uint)*(byte *)(iVar4 + 0x91) << 10;
  if ((uVar10 & 0x30000) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x635,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar6 = param_1 * 0x5a;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar7 + iVar6 + 0x26);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar9 = *(code **)(_r_plf_funcs_p + 0xbc);
  *(ushort *)(iVar7 + iVar6 + 0x26) = uVar2 & 0x3ff | (ushort)uVar10;
  iVar7 = (*pcVar9)(0x400,pcVar9);
  uVar2 = *(ushort *)(iVar7 + iVar6 + 4);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar7 + iVar6 + 4) = uVar2 & 0xffcf | 0x10;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(short *)(iVar6 + 0x34 + iVar7) = (short)((uVar5 * 0xe + 0x1400) * 0x10000 >> 0x10);
  cVar8 = *(char *)(iVar4 + 0x90);
  if (cVar8 == '\x03') {
    cVar8 = '\x02';
  }
  iVar7 = (**(code **)(_r_modules_funcs_p + 4))(0x22,cVar8,*(code **)(_r_modules_funcs_p + 4));
  bVar1 = *(byte *)(iVar4 + 0x87);
  *(int *)(iVar4 + 0x6c) = *(int *)(iVar4 + 0x6c) + iVar7 + 0x96;
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar2 = *(ushort *)(iVar7 + uVar5 * 0xe);
  iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(uVar5 * 0xe + iVar7) = ((ushort)bVar1 * 9 + 2 & 0xff) * 0xe + 0x1400 | uVar2 & 0x8000;
  (**(code **)(_r_ip_funcs_p + 0x1b0))(param_1,8,0,1,1,0,0);
  *(undefined1 *)(iVar4 + 0x92) = 3;
  return;
}


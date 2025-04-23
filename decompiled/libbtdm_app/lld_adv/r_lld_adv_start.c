/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_start(uint param_1,undefined2 *param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  void *__s;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  
  if (*(int *)(&lld_adv_env + param_1 * 4) != 0) {
    return 0xc;
  }
  __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                          (0x9c,0,*(code **)(_r_modules_funcs_p + 0x120));
  *(void **)(&lld_adv_env + param_1 * 4) = __s;
  if (__s == (void *)0x0) {
    (**(code **)(_r_plf_funcs_p + 8))("lld_adv.c",0xd4c,*(code **)(_r_plf_funcs_p + 8));
    return 0xc;
  }
  iVar5 = param_1 * 0x5a;
  uVar6 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
  memset(__s,0,0x9c);
  (**(code **)(_r_ip_funcs_p + 0x77c))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x77c));
  uVar7 = (**(code **)(_r_ip_funcs_p + 0x780))
                    (param_1,param_2,uVar6,*(code **)(_r_ip_funcs_p + 0x780));
  (**(code **)(_r_ip_funcs_p + 0x784))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x784));
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0x16 + iVar8) = 0x8027;
  if (*(char *)((int)__s + 0x8d) != '\x7f') {
    pcVar10 = *(code **)(_r_modules_funcs_p + 0x1fc);
    uVar9 = (*_lld_exp_sync_pos_tab)(0,_lld_exp_sync_pos_tab);
    (*pcVar10)(param_1,uVar9);
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0x18 + iVar8) = 0;
  (**(code **)(_r_ip_funcs_p + 0x1e0))(param_1,uVar7,*(code **)(_r_ip_funcs_p + 0x1e0));
  bVar1 = *(byte *)((int)__s + 0x87);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + 0x1c + iVar8) = ((ushort)bVar1 * 9 & 0xff) * 0xe + 0x1400;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0xc + iVar8) = 0xbed6;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0xe + iVar8) = 0x8e89;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0x10 + iVar8) = 0x5555;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0x12 + iVar8) = 0x55;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0x28 + iVar8) = 0;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 0x2a + iVar8) = 0;
  uVar3 = *(ushort *)((int)__s + 0x74);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + 0x20 + iVar8) = (ushort)((int)(uint)uVar3 >> 1) & 8;
  bVar1 = *(byte *)((int)__s + 0x90);
  bVar2 = *(byte *)((int)__s + 0x8e);
  if ((bVar1 & 0xfc) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x18e,*(code **)(_r_plf_funcs_p + 8));
  }
  if ((bVar2 & 0xfc) == 0) {
    if (bVar2 < 4) goto _L1099;
  }
  else {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",399,*(code **)(_r_plf_funcs_p + 8));
  }
  (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",400,*(code **)(_r_plf_funcs_p + 8));
_L1099:
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + 4 + iVar8) = (ushort)bVar2 | (ushort)bVar1 << 4 | (ushort)bVar2 << 2;
  bVar1 = *(byte *)(param_2 + 0xf);
  if (0x1f < param_1) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(ushort *)(iVar5 + 2 + iVar8) = (ushort)((bVar1 & 1) << 7) | (ushort)param_1 | 0x800;
  uVar4 = *param_2;
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 6 + iVar8) = uVar4;
  uVar4 = param_2[1];
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 8 + iVar8) = uVar4;
  uVar4 = param_2[2];
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  *(undefined2 *)(iVar5 + 10 + iVar8) = uVar4;
  bVar1 = *(byte *)((int)param_2 + 0x1d);
  if ((bVar1 & 0xf8) != 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x641,*(code **)(_r_plf_funcs_p + 8));
  }
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = *(ushort *)(iVar8 + iVar5 + 0x26);
  iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  pcVar10 = *(code **)(_r_ip_funcs_p + 0x788);
  *(ushort *)(iVar5 + 0x26 + iVar8) = uVar3 & 0xff1f | (ushort)bVar1 << 5;
  (*pcVar10)(param_1,param_2,uVar6,pcVar10);
  (**(code **)(_r_ip_funcs_p + 0x194))(__s,*(code **)(_r_ip_funcs_p + 0x194));
  return 0;
}


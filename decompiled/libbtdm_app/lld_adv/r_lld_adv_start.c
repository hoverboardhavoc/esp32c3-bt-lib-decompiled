/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
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
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  void *__s;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  code *pcVar11;
  
  if (*(int *)(&lld_adv_env + param_1 * 4) == 0) {
    __s = (void *)(**(code **)(_r_modules_funcs_p + 0x120))
                            (0x9c,0,*(code **)(_r_modules_funcs_p + 0x120));
    *(void **)(&lld_adv_env + param_1 * 4) = __s;
    if (__s != (void *)0x0) {
      iVar4 = param_1 * 0x5a;
      uVar5 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      memset(__s,0,0x9c);
      (**(code **)(_r_ip_funcs_p + 0x77c))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x77c));
      uVar6 = (**(code **)(_r_ip_funcs_p + 0x780))
                        (param_1,param_2,uVar5,*(code **)(_r_ip_funcs_p + 0x780));
      (**(code **)(_r_ip_funcs_p + 0x784))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x784));
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 0x16) = 0x8027;
      if (*(char *)((int)__s + 0x8d) != '\x7f') {
        pcVar11 = *(code **)(_r_modules_funcs_p + 0x1fc);
        uVar8 = (*_rwip_rf)(0,_rwip_rf);
        (*pcVar11)(param_1,uVar8);
      }
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = _r_ip_funcs_p;
      *(undefined2 *)(iVar9 + iVar4 + 0x18) = 0;
      (**(code **)(iVar7 + 0x1e0))(param_1,uVar6,*(code **)(iVar7 + 0x1e0));
      bVar1 = *(byte *)((int)__s + 0x87);
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = _r_plf_funcs_p;
      *(ushort *)(iVar9 + iVar4 + 0x1c) = ((ushort)bVar1 * 9 & 0xff) * 0xe + 0x1400;
      iVar7 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 0xc) = 0xbed6;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 0xe) = 0x8e89;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 0x10) = 0x5555;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 0x12) = 0x55;
      iVar9 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar7 = _r_plf_funcs_p;
      *(undefined2 *)(iVar9 + iVar4 + 0x28) = 0;
      iVar9 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
      iVar7 = _r_plf_funcs_p;
      *(undefined2 *)(iVar9 + iVar4 + 0x2a) = 0;
      uVar2 = *(ushort *)((int)__s + 0x74);
      iVar7 = (**(code **)(iVar7 + 0xbc))(0x400,*(code **)(iVar7 + 0xbc));
      *(ushort *)(iVar7 + iVar4 + 0x20) = (ushort)((int)(uint)uVar2 >> 1) & 8;
      bVar1 = *(byte *)((int)__s + 0x8e);
      uVar10 = (uint)*(byte *)((int)__s + 0x90) << 4;
      if ((uVar10 & 0xffffffcf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x18e,*(code **)(_r_plf_funcs_p + 8));
      }
      if (((uint)bVar1 << 2 & 0xfffffff3) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",399,*(code **)(_r_plf_funcs_p + 8));
      }
      if ((bVar1 & 0xfc) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",400,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar4 + 4) = (ushort)uVar10 | (ushort)((uint)bVar1 << 2) | (ushort)bVar1;
      bVar1 = *(byte *)(param_2 + 0xf);
      if ((param_1 & 0xffffffe0) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0xe6,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar7 + iVar4 + 2) = (ushort)((bVar1 & 1) << 7) | (ushort)param_1 | 0x800;
      uVar3 = *param_2;
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 6) = uVar3;
      uVar3 = param_2[1];
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 8) = uVar3;
      uVar3 = param_2[2];
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)(iVar7 + iVar4 + 10) = uVar3;
      uVar10 = (uint)*(byte *)((int)param_2 + 0x1d) << 5;
      if ((uVar10 & 0xffffff1f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x641,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(ushort *)(iVar7 + iVar4 + 0x26);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x788);
      *(ushort *)(iVar4 + 0x26 + iVar7) = uVar2 & 0xff1f | (ushort)uVar10;
      (*pcVar11)(param_1,param_2,uVar5,pcVar11);
      (**(code **)(_r_ip_funcs_p + 0x194))(__s,*(code **)(_r_ip_funcs_p + 0x194));
      return 0;
    }
    (**(code **)(_r_plf_funcs_p + 8))("lld_adv.c",0xd35,*(code **)(_r_plf_funcs_p + 8));
  }
  return 0xc;
}


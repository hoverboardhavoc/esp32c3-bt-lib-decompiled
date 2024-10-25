/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_evt_start_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_evt_start_cbk(int param_1)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  byte bStack_51;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_34;
  
  iVar5 = (**(code **)(_r_ip_funcs_p + 0x834))(1,param_1,*(code **)(_r_ip_funcs_p + 0x834));
  iVar8 = _lld_init_env;
  if (iVar5 == 0) {
    if (param_1 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("lld_init.c",0x57f,*(code **)(_r_plf_funcs_p + 8));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x52);
      uVar10 = (uint)bVar1;
      iVar5 = uVar10 * 0x5a;
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar2 = *(undefined1 *)(param_1 + 0x3e);
      uVar11 = *(ushort *)(iVar6 + iVar5) & 0x1f;
      (**(code **)(_r_modules_funcs_p + 0x1e0))
                (uVar11,uVar10,&bStack_51,&uStack_50,*(code **)(_r_modules_funcs_p + 0x1e0));
      if (((uint)bStack_51 << 7 & 0xffffff7f) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x82,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar6 + iVar5);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(ushort *)(iVar6 + iVar5) = uVar3 & 0xff7f | (ushort)((uint)bStack_51 << 7);
      uVar12 = (uStack_50 & 0xff) << 6;
      if ((uVar12 & 0xffffffbf) != 0) {
        (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x8e,*(code **)(_r_plf_funcs_p + 8));
      }
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar3 = *(ushort *)(iVar6 + iVar5);
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _r_ip_funcs_p;
      *(ushort *)(iVar7 + iVar5) = uVar3 & 0xffbf | (ushort)uVar12;
      uVar4 = (**(code **)(iVar6 + 0x44c))
                        (*(undefined2 *)(iVar8 + 0xc),*(undefined2 *)(iVar8 + 0xe),uVar2,
                         *(undefined4 *)(param_1 + 4),*(code **)(iVar6 + 0x44c));
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _r_ip_funcs_p;
      *(undefined2 *)(iVar7 + iVar5 + 0x1e) = uVar4;
      uVar4 = (**(code **)(iVar6 + 0x44c))
                        (*(undefined2 *)(iVar8 + 0x16),*(undefined2 *)(iVar8 + 0x18),uVar2,
                         *(undefined4 *)(param_1 + 4),*(code **)(iVar6 + 0x44c));
      iVar7 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar6 = _r_ip_funcs_p;
      *(undefined2 *)(iVar7 + iVar5 + 0x36) = uVar4;
      uVar4 = (**(code **)(iVar6 + 0x44c))
                        (*(undefined2 *)(iVar8 + 0x20),*(undefined2 *)(iVar8 + 0x22),uVar2,
                         *(undefined4 *)(param_1 + 4),*(code **)(iVar6 + 0x44c));
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar9 = *(code **)(_r_ip_funcs_p + 0x490);
      *(undefined2 *)(iVar5 + 0x3a + iVar8) = uVar4;
      (*pcVar9)(uVar10,uVar11,pcVar9);
      uStack_50 = *(uint *)(_r_ip_funcs_p + 0x460);
      uStack_3b = 0;
      uStack_4c = *(undefined4 *)(param_1 + 4);
      uStack_37 = 0;
      uStack_34 = 0;
      uStack_48 = *(undefined4 *)(param_1 + 8);
      uStack_40 = (uint)*(byte *)(param_1 + 0x51);
      uStack_44 = *(undefined4 *)(param_1 + 0x10);
      uStack_3c = *(undefined1 *)(param_1 + 0x16);
      uStack_3a = rwip_priority;
      uStack_39 = 0xf;
      uStack_36 = *(char *)(param_1 + 0x3d) == '\x01';
      bStack_38 = bVar1;
      (**(code **)(_r_ip_funcs_p + 0x6c8))(&uStack_50,*(code **)(_r_ip_funcs_p + 0x6c8));
      (**(code **)(_r_ip_funcs_p + 0x714))(1,*(code **)(_r_ip_funcs_p + 0x714));
      *(undefined1 *)(param_1 + 0x31) = 1;
    }
    (**(code **)(_r_ip_funcs_p + 0x834))(0,param_1,*(code **)(_r_ip_funcs_p + 0x834));
  }
  return;
}


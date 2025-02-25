/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx_connect_ind(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  ushort uVar6;
  uint uVar7;
  undefined1 auStack_5c [8];
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined4 uStack_44;
  undefined2 uStack_40;
  byte bStack_31;
  ushort uStack_30;
  ushort uStack_2e;
  ushort uStack_2c;
  ushort uStack_2a;
  undefined1 auStack_28 [4];
  byte bStack_24;
  byte bStack_23;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar2 = (uint)bVar1 * 0x14;
  if ((*(ushort *)(iVar3 + iVar2 + 4) & 0xf) != 5) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7c9,*(code **)(_r_plf_funcs_p + 8));
    return 0;
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (*(undefined2 *)(iVar3 + iVar2 + 0x12),
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(&uStack_44,pvVar4,0x22);
  if (0xc76 < (uStack_2a - 10 & 0xffff)) {
    return 0;
  }
  if (0xc7a < (uStack_2e - 6 & 0xffff)) {
    return 0;
  }
  if (499 < uStack_2c) {
    return 0;
  }
  if ((uint)uStack_2a << 2 <= (uStack_2c + 1) * (uint)uStack_2e) {
    return 0;
  }
  uVar5 = (*(code *)_r_modules_funcs_p[3])(auStack_28,(code *)_r_modules_funcs_p[3]);
  if (uVar5 < 2) {
    return 0;
  }
  if ((bStack_24 & 0xe0) != 0) {
    return 0;
  }
  if (0xb < (byte)((bStack_23 & 0x1f) - 5)) {
    return 0;
  }
  uVar5 = (uint)uStack_2e;
  if (uVar5 < uStack_30) {
    return 0;
  }
  if (bStack_31 == 0) {
    return 0;
  }
  iVar3 = 8;
  if (uVar5 < 10) {
    iVar3 = uVar5 - 1;
  }
  if (iVar3 < (int)(uint)bStack_31) {
    return 0;
  }
  iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar5 = (uint)*(ushort *)(iVar3 + iVar2 + 0xe);
  if (uVar5 == 0) {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = *(ushort *)(iVar3 + iVar2 + 4) >> 6 & 1;
  }
  else {
    pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar5 + 0x18 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(auStack_5c,pvVar4,6);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar2 = ((uVar5 - 0xc60) / 0x34 & 0xff) * 0x34;
    uVar6 = *(ushort *)(iVar3 + iVar2);
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = uVar6 & 1;
    if ((((*(ushort *)(iVar3 + iVar2) >> 1 & 1) != 0) &&
        (iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
        (*(ushort *)(iVar3 + iVar2) >> 3 & 1) != 0)) &&
       (iVar3 = (*(code *)*_r_modules_funcs_p)(&uStack_44,auStack_5c,(code *)*_r_modules_funcs_p),
       iVar3 == 0)) {
      uVar6 = uVar6 | 2;
      uStack_54 = uStack_44;
      uStack_50 = uStack_40;
      goto _L661;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if (((*(ushort *)(iVar3 + iVar2) >> 1 & 1) != 0) &&
       (iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
       -1 < (int)((uint)*(ushort *)(iVar3 + iVar2) << 0x14))) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7fc,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  uStack_54 = 0;
  uStack_50 = 0;
_L661:
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar2 + param_1 * 0x5a + 0x14) >> 2 & 1) == 0) {
    uStack_4c = 0;
    uStack_48 = 0;
  }
  else {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar5 = (*(ushort *)(param_1 * 0x5a + 0x2c + iVar2) - 0xc60) / 0x34;
    uVar7 = uVar5 & 0xff;
    if (9 < uVar7) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x813,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar2 = (uVar5 & 0xff) * 0x34;
    if ((*(ushort *)(iVar3 + iVar2) >> 5 & 1) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x814,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar3 + iVar2) >> 7 & 1) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x815,*(code **)(_r_plf_funcs_p + 8));
    }
    pvVar4 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar7 * 0x34 + 0xc8e,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(&uStack_4c,pvVar4,6);
  }
  (**(code **)(_r_ip_funcs_p + 0x778))
            (param_1,&uStack_44,auStack_5c,&uStack_54,&uStack_4c,uVar6,
             *(code **)(_r_ip_funcs_p + 0x778));
  return 1;
}


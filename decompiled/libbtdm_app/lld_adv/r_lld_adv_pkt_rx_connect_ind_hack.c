/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_adv_pkt_rx_connect_ind_hack(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  ushort uVar6;
  uint uVar7;
  undefined1 auStack_5c [8];
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined4 uStack_4c;
  undefined2 uStack_48;
  undefined4 uStack_44;
  undefined2 uStack_40;
  undefined1 auStack_34 [3];
  byte bStack_31;
  ushort uStack_30;
  ushort uStack_2e;
  ushort uStack_2c;
  ushort uStack_2a;
  uint uStack_28;
  byte bStack_24;
  byte bStack_23;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (*(undefined2 *)((uint)bVar1 * 0x14 + 0x12 + iVar4),
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(auStack_34,pvVar5,0x22);
  if (((uStack_28 & 0xffff) == uStack_28 >> 0x10) ||
     (((iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
       *(char *)(iVar4 + 0x24) != '\0' && (*(code **)(_r_ip_funcs_p + 0x9e0) != (code *)0x0)) &&
      (iVar4 = (**(code **)(_r_ip_funcs_p + 0x9e0))(uStack_28), iVar4 == 0)))) {
    return 0;
  }
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  iVar4 = (uint)bVar1 * 0x14;
  if ((*(ushort *)(iVar2 + iVar4 + 4) & 0xf) != 5) {
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7b2,*(code **)(_r_plf_funcs_p + 8));
    return 0;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                             (*(undefined2 *)(iVar2 + iVar4 + 0x12),
                              *(code **)(_r_plf_funcs_p + 0xbc));
  memcpy(&uStack_44,pvVar5,0x22);
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
  uVar3 = (*(code *)_r_modules_funcs_p[3])(&uStack_28,(code *)_r_modules_funcs_p[3]);
  if (uVar3 < 2) {
    return 0;
  }
  if ((bStack_24 & 0xe0) != 0) {
    return 0;
  }
  if (0xb < (byte)((bStack_23 & 0x1f) - 5)) {
    return 0;
  }
  uVar3 = (uint)uStack_2e;
  if (uVar3 < uStack_30) {
    return 0;
  }
  if (bStack_31 == 0) {
    return 0;
  }
  iVar2 = 8;
  if (uVar3 < 10) {
    iVar2 = uVar3 - 1;
  }
  if (iVar2 < (int)(uint)bStack_31) {
    return 0;
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
  uVar3 = (uint)*(ushort *)(iVar2 + iVar4 + 0xe);
  if (uVar3 == 0) {
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = *(ushort *)(iVar2 + iVar4 + 4) >> 6 & 1;
  }
  else {
    pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar3 + 0x18 & 0xffff,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(auStack_5c,pvVar5,6);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = ((uVar3 - 0xc60) / 0x34 & 0xff) * 0x34;
    uVar6 = *(ushort *)(iVar2 + iVar4);
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = uVar6 & 1;
    if ((((*(ushort *)(iVar2 + iVar4) >> 1 & 1) != 0) &&
        (iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
        (*(ushort *)(iVar2 + iVar4) >> 3 & 1) != 0)) &&
       (iVar2 = (*(code *)*_r_modules_funcs_p)(&uStack_44,auStack_5c,(code *)*_r_modules_funcs_p),
       iVar2 == 0)) {
      uVar6 = uVar6 | 2;
      uStack_54 = uStack_44;
      uStack_50 = uStack_40;
      goto _L661;
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if (((*(ushort *)(iVar2 + iVar4) >> 1 & 1) != 0) &&
       (iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc)),
       -1 < (int)((uint)*(ushort *)(iVar2 + iVar4) << 0x14))) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7e5,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  uStack_54 = 0;
  uStack_50 = 0;
_L661:
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
  if ((*(ushort *)(iVar4 + param_1 * 0x5a + 0x14) >> 2 & 1) == 0) {
    uStack_4c = 0;
    uStack_48 = 0;
  }
  else {
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = (*(ushort *)(param_1 * 0x5a + 0x2c + iVar4) - 0xc60) / 0x34;
    uVar7 = uVar3 & 0xff;
    if (9 < uVar7) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7fc,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    iVar4 = (uVar3 & 0xff) * 0x34;
    if ((*(ushort *)(iVar2 + iVar4) >> 5 & 1) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7fd,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar2 = (**(code **)(_r_plf_funcs_p + 0xbc))(0xc60,*(code **)(_r_plf_funcs_p + 0xbc));
    if ((*(ushort *)(iVar2 + iVar4) >> 7 & 1) == 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_adv.c",0x7fe,*(code **)(_r_plf_funcs_p + 8));
    }
    pvVar5 = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))
                               (uVar7 * 0x34 + 0xc8e,*(code **)(_r_plf_funcs_p + 0xbc));
    memcpy(&uStack_4c,pvVar5,6);
  }
  (**(code **)(_r_ip_funcs_p + 0x778))
            (param_1,&uStack_44,auStack_5c,&uStack_54,&uStack_4c,uVar6,
             *(code **)(_r_ip_funcs_p + 0x778));
  return 1;
}


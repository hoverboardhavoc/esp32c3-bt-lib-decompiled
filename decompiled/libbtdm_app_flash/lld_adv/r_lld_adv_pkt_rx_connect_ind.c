/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_pkt_rx_connect_ind
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
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar2 = (uint)bVar1 * 0x14;
  if ((*(ushort *)(iVar3 + iVar2 + 4) & 0xf) != 5) {
    r_assert_err(0,"lld_adv.c",0x7b2);
    return 0;
  }
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  pvVar4 = (void *)r_emi_get_mem_addr_by_offset(*(undefined2 *)(iVar3 + iVar2 + 0x12));
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
  uVar5 = r_co_nb_good_le_channels(auStack_28);
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
  iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar5 = (uint)*(ushort *)(iVar2 + 0xe + iVar3);
  if (uVar5 == 0) {
    iVar3 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar6 = *(ushort *)(iVar3 + iVar2 + 4) >> 6 & 1;
  }
  else {
    pvVar4 = (void *)r_emi_get_mem_addr_by_offset(uVar5 + 0x18 & 0xffff);
    memcpy(auStack_5c,pvVar4,6);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    iVar2 = ((uVar5 - 0xc60) / 0x34 & 0xff) * 0x34;
    uVar6 = *(ushort *)(iVar3 + iVar2);
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    uVar6 = uVar6 & 1;
    if ((((*(ushort *)(iVar3 + iVar2) >> 1 & 1) != 0) &&
        (iVar3 = r_emi_get_mem_addr_by_offset(0xc60), (*(ushort *)(iVar3 + iVar2) >> 3 & 1) != 0))
       && (iVar3 = r_co_bdaddr_compare(&uStack_44,auStack_5c), iVar3 == 0)) {
      uVar6 = uVar6 | 2;
      uStack_54 = uStack_44;
      uStack_50 = uStack_40;
      goto _L745;
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    if (((*(ushort *)(iVar3 + iVar2) >> 1 & 1) != 0) &&
       (iVar3 = r_emi_get_mem_addr_by_offset(0xc60),
       -1 < (int)((uint)*(ushort *)(iVar3 + iVar2) << 0x14))) {
      r_assert_err(0,"lld_adv.c",0x7e5);
    }
  }
  uStack_54 = 0;
  uStack_50 = 0;
_L745:
  iVar2 = r_emi_get_mem_addr_by_offset(0x400);
  if ((*(ushort *)(iVar2 + param_1 * 0x5a + 0x14) >> 2 & 1) == 0) {
    uStack_4c = 0;
    uStack_48 = 0;
  }
  else {
    iVar2 = r_emi_get_mem_addr_by_offset(0x400);
    uVar5 = (*(ushort *)(param_1 * 0x5a + 0x2c + iVar2) - 0xc60) / 0x34;
    uVar7 = uVar5 & 0xff;
    if (9 < uVar7) {
      r_assert_err(0,"lld_adv.c",0x7fc);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    iVar2 = (uVar5 & 0xff) * 0x34;
    if ((*(ushort *)(iVar3 + iVar2) >> 5 & 1) == 0) {
      r_assert_err(0,"lld_adv.c",0x7fd);
    }
    iVar3 = r_emi_get_mem_addr_by_offset(0xc60);
    if ((*(ushort *)(iVar3 + iVar2) >> 7 & 1) == 0) {
      r_assert_err(0,"lld_adv.c",0x7fe);
    }
    pvVar4 = (void *)r_emi_get_mem_addr_by_offset(uVar7 * 0x34 + 0xc8e);
    memcpy(&uStack_4c,pvVar4,6);
  }
  r_lld_adv_pkt_rx_connect_post(param_1,&uStack_44,auStack_5c,&uStack_54,&uStack_4c,uVar6);
  return 1;
}


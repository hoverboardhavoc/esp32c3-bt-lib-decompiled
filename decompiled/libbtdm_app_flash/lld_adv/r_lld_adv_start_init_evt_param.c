/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_start_init_evt_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_start_init_evt_param(int param_1,int param_2)

{
  code cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *__dest;
  short sVar5;
  ushort uVar6;
  byte bVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  *(code **)(iVar2 + 0x20) = r_lld_adv_evt_canceled_cbk_hack;
  *(code **)(iVar2 + 0x18) = r_lld_adv_evt_start_cbk;
  bVar7 = DAT_0001700d;
  cVar1 = r_assert_err;
  *(char *)(iVar2 + 0x87) = (char)param_1;
  *(code *)(iVar2 + 0x16) = cVar1;
  *(ushort *)(iVar2 + 0x14) = bVar7 & 0xf | 0x6000;
  uVar8 = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 8) = 0;
  *(undefined4 *)(iVar2 + 100) = uVar8;
  *(undefined2 *)(iVar2 + 0x74) = *(undefined2 *)(param_2 + 0x18);
  *(undefined1 *)(iVar2 + 0x8a) = *(undefined1 *)(param_2 + 0x26);
  memcpy((void *)(iVar2 + 0x2c),(void *)(param_2 + 6),6);
  *(undefined1 *)(iVar2 + 0x8b) = *(undefined1 *)(param_2 + 0x1e);
  *(undefined1 *)(iVar2 + 0x8c) = *(undefined1 *)(param_2 + 0x1f);
  *(undefined1 *)(iVar2 + 0x8d) = *(undefined1 *)(param_2 + 0x21);
  *(undefined1 *)(iVar2 + 0x8f) = *(undefined1 *)(param_2 + 0x23);
  bVar7 = *(byte *)(param_2 + 0x22);
  if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar7 = bVar7 - 1;
  }
  *(byte *)(iVar2 + 0x8e) = bVar7;
  bVar7 = *(byte *)(param_2 + 0x24);
  if ((bVar7 < 3) || (*(char *)(_p_lld_env + 0xda) == '\0')) {
    bVar7 = bVar7 - 1;
  }
  *(byte *)(iVar2 + 0x90) = bVar7;
  *(undefined *)(iVar2 + 0x93) =
       (&one_bits)[*(byte *)(param_2 + 0x1d) >> 4] + (&one_bits)[*(byte *)(param_2 + 0x1d) & 0xf];
  iVar3 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
  *(ushort *)(iVar2 + 0x76) =
       *(ushort *)(iVar2 + 0x76) & 0xf000 | (ushort)((uint)(iVar3 << 0x14) >> 0x14);
  if ((*(byte *)(param_2 + 0x25) & 0xf0) != 0) {
    r_assert_param(0xf000,0x10000,0xbcc);
  }
  *(ushort *)(iVar2 + 0x76) =
       (ushort)*(byte *)(param_2 + 0x25) << 0xc |
       (ushort)(((uint)*(ushort *)(iVar2 + 0x76) << 0x14) >> 0x14);
  *(ushort *)(iVar2 + 0x78) = (ushort)*(byte *)(param_2 + 0x1c);
  *(undefined1 *)(iVar2 + 0x88) = 0xff;
  *(undefined2 *)(iVar2 + 0x82) = *(undefined2 *)(param_2 + 0x14);
  *(undefined2 *)(iVar2 + 0x7e) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)(iVar2 + 0x84) = *(undefined2 *)(param_2 + 0x16);
  *(undefined2 *)(iVar2 + 0x80) = *(undefined2 *)(param_2 + 0x12);
  if ((*(ushort *)(iVar2 + 0x74) & 0x10) == 0) {
    iVar3 = r_sdk_config_get_opts_ext();
    if (*(char *)(iVar3 + 0x18) == '\0') {
      r_assert_err(0,0x10000,0xbda);
    }
    *(bool *)(iVar2 + 0x95) = *(char *)(iVar2 + 0x8f) != '\0';
    r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar2 + 0x87));
    if (*(char *)(iVar2 + 0x95) == '\0') {
      return;
    }
    *(code **)(iVar2 + 0x54) = r_lld_adv_aux_evt_canceled_cbk;
    *(code **)(iVar2 + 0x4c) = r_lld_adv_aux_evt_start_cbk;
    cVar1 = r_emi_get_mem_addr_by_offset;
    *(undefined4 *)(iVar2 + 0x50) = 0;
    *(code *)(iVar2 + 0x4a) = cVar1;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined4 *)(iVar2 + 0x44) = *(undefined4 *)(iVar2 + 0x10);
    *(ushort *)(iVar2 + 0x48) = DAT_00017011 & 0xf | 0x6000;
    return;
  }
  uVar11 = (uint)*(byte *)(iVar2 + 0x87) * 9 & 0xff;
  uVar12 = uVar11 + 1 & 0xff;
  switch(*(ushort *)(iVar2 + 0x74) - 0x10) {
  case 0:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x5b2 + -300 + (uint)_sdk_cfg_priv_opts;
    uVar6 = 2;
    break;
  default:
    r_assert_err(0,0x10000,0xc13);
    goto _L1066;
  case 2:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    uVar6 = 6;
    break;
  case 3:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
_L1066:
    uVar6 = 0;
    break;
  case 5:
  case 0xd:
    *(uint *)(iVar2 + 0x10) =
         (uint)*(byte *)(iVar2 + 0x93) * 0x72e + -300 + (uint)_sdk_cfg_priv_opts;
    uVar6 = 1;
    uVar9 = *(byte *)(param_2 + 0x1f) & 1;
    goto _L1031;
  }
  uVar9 = 0;
_L1031:
  iVar10 = uVar11 * 0xe;
  bVar7 = *(byte *)(param_2 + 0x1e);
  iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar10 + 2 + iVar3) =
       (ushort)((bVar7 & 1) << 6) | (ushort)(uVar9 << 7) | uVar6 | 0x620;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x14) == 0) {
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar10 + 4 + iVar3) = 0;
      iVar3 = r_bt_rf_coex_st_param_get(2);
      if (iVar3 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [LDC] [EN%d] [%d] \n",*(undefined1 *)(iVar3 + 4),
                     *(undefined1 *)(iVar3 + 5));
        }
        bVar7 = *(byte *)(iVar3 + 5);
        if ((bVar7 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar14 = iVar10 + 10;
        uVar6 = *(ushort *)(iVar4 + iVar14);
        iVar4 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar4 + iVar14) = uVar6 & 0xf0ff | (ushort)bVar7 << 8;
        bVar7 = *(byte *)(iVar3 + 4);
        iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar6 = *(ushort *)(iVar3 + iVar14);
        iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar3 + iVar14) = uVar6 & 0xefff | (ushort)bVar7 << 0xc;
      }
      goto _L1035;
    }
    sVar5 = *(short *)(param_2 + 0x10);
    uVar6 = *(ushort *)(param_2 + 0x14) & 0xff;
  }
  else {
    sVar5 = (ushort)*(byte *)(iVar2 + 0x87) * 0x4b + 0x2000;
    __dest = (void *)r_emi_get_mem_addr_by_offset(sVar5);
    memcpy(__dest,(void *)(param_2 + 6),6);
    uVar6 = 6;
  }
  r_lld_adv_adv_data_set_hack(param_1,uVar6,sVar5,0,0);
_L1035:
  iVar4 = uVar12 * 0xe;
  bVar7 = *(byte *)(param_2 + 0x1e);
  iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
  iVar14 = iVar4 + 2;
  *(ushort *)(iVar3 + iVar14) = (ushort)((bVar7 & 1) << 6) | 4;
  if ((*(ushort *)(iVar2 + 0x74) & 4) == 0) {
    if (*(ushort *)(param_2 + 0x16) == 0) {
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = *(ushort *)(iVar3 + iVar14);
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar3 + iVar14) = uVar6 & 0xff | 0x600;
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      *(undefined2 *)(iVar4 + 4 + iVar3) = 0;
      iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
      uVar6 = *(ushort *)(iVar3 + iVar4);
      iVar3 = r_emi_get_mem_addr_by_offset();
      *(ushort *)(iVar3 + iVar4) = (short)uVar11 * 0xe + 0x1400U | uVar6 & 0x8000;
      iVar3 = r_bt_rf_coex_st_param_get(2);
      if (iVar3 != 0) {
        if (2 < _g_bt_plf_log_level) {
          ets_printf("TX PTI [LDC ADV] [EN%d] [%d] \n",*(undefined1 *)(iVar3 + 4),
                     *(undefined1 *)(iVar3 + 5));
        }
        bVar7 = *(byte *)(iVar3 + 5);
        if ((bVar7 & 0xf0) != 0) {
          r_assert_err(0,0x10000,0x33f);
        }
        iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
        iVar13 = iVar4 + 10;
        uVar6 = *(ushort *)(iVar14 + iVar13);
        iVar14 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar14 + iVar13) = uVar6 & 0xf0ff | (ushort)bVar7 << 8;
        bVar7 = *(byte *)(iVar3 + 4);
        iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar6 = *(ushort *)(iVar3 + iVar13);
        iVar3 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar3 + iVar13) = uVar6 & 0xefff | (ushort)bVar7 << 0xc;
      }
    }
    else {
      r_lld_adv_scan_rsp_data_set_hack
                (param_1,*(ushort *)(param_2 + 0x16) & 0xff,*(undefined2 *)(param_2 + 0x12),0,0);
    }
  }
  if ((*(ushort *)(iVar2 + 0x74) & 6) == 2) {
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar6 = *(ushort *)(iVar2 + iVar10);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar2 + iVar10) = (short)uVar12 * 0xe + 0x1400U | uVar6 & 0x8000;
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    uVar6 = *(ushort *)(iVar2 + iVar4);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar4 + iVar2) = (ushort)(((uint)uVar6 << 0x11) >> 0x11);
  }
  else {
    iVar2 = r_emi_get_mem_addr_by_offset();
    uVar6 = *(ushort *)(iVar2 + iVar10);
    iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
    *(ushort *)(iVar2 + iVar10) = uVar6 & 0x8000;
  }
  iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
  uVar6 = *(ushort *)(iVar2 + iVar10);
  iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
  *(ushort *)(iVar10 + iVar2) = (ushort)(((uint)uVar6 << 0x11) >> 0x11);
  return;
}


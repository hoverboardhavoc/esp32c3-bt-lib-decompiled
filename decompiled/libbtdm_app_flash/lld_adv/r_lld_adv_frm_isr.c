/*
 * Last changed at upstream commit f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * https://github.com/espressif/esp32c3-bt-lib/commit/f23a340e82d6a4be40f83214385a98c5bd30ccdd
 * Upstream date: 2025-04-03 18:07:15 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(a684dd5)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_frm_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_frm_isr(uint param_1,int param_2,int param_3)

{
  int iVar1;
  ushort uVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  char cVar9;
  byte bVar10;
  code cVar11;
  
  iVar1 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar1 == 0) {
    uVar7 = 0xae8;
    goto _L980;
  }
  if ((*(char *)(iVar1 + 0x95) == '\0') || (iVar5 = iVar1 + 0x34, *(int *)(iVar1 + 0x38) != param_2)
     ) {
    iVar5 = iVar1;
  }
  r_sch_arb_remove(iVar5,1);
  bVar10 = *(char *)(iVar1 + 0x86) + 1;
  *(byte *)(iVar1 + 0x86) = bVar10;
  if ((*(char *)(iVar1 + 0x89) == '\x02') ||
     ((*(ushort *)(iVar1 + 0x78) != 0 && (*(ushort *)(iVar1 + 0x78) <= (ushort)bVar10)))) {
    while (iVar5 = r_lld_rxdesc_check_hack(param_1), iVar5 != 0) {
      r_lld_rxdesc_free();
    }
    uVar6 = 0;
    if ((*(ushort *)(iVar1 + 0x78) != 0) &&
       (*(ushort *)(iVar1 + 0x78) <= (ushort)*(byte *)(iVar1 + 0x86))) {
      uVar6 = 0x43;
    }
  }
  else {
    iVar5 = r_lld_adv_pkt_rx(*(undefined1 *)(iVar1 + 0x87));
    if (iVar5 != 0) {
      uVar6 = 0;
      iVar1 = 0;
      goto _L979;
    }
    if ((*(short *)(iVar1 + 0x24) != 0) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      r_lld_adv_adv_data_set_hack(param_1,*(undefined1 *)(iVar1 + 0x28),1,1);
      *(undefined2 *)(iVar1 + 0x24) = 0;
    }
    if ((*(short *)(iVar1 + 0x26) != 0) &&
       (((*(ushort *)(iVar1 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar1 + 0x74) & 0x14) == 0x10))))
    {
      r_lld_adv_scan_rsp_data_set_hack(param_1,*(undefined1 *)(iVar1 + 0x2a),1,1);
      *(undefined2 *)(iVar1 + 0x26) = 0;
    }
    if (((*(ushort *)(iVar1 + 0x74) & 0x13) == 0) && (*(char *)(iVar1 + 0x94) != '\0')) {
      if (*(int *)(iVar1 + 0x68) != 0) {
        uVar2 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
        *(ushort *)(iVar1 + 0x76) = *(ushort *)(iVar1 + 0x76) & 0xf000 | uVar2 & 0xfff;
      }
      r_lld_adv_ext_chain_construct(*(undefined1 *)(iVar1 + 0x87));
      *(undefined1 *)(iVar1 + 0x94) = 0;
    }
    bVar10 = DAT_0001700f;
    if ((*(ushort *)(iVar1 + 0x74) & 8) == 0) {
      if ((*(ushort *)(iVar1 + 0x74) & 0x10) == 0) {
        if ((*(char *)(iVar1 + 0x95) == '\0') || (*(int *)(iVar1 + 0x38) == param_2)) {
          iVar5 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar5 + 0x18) == '\0') {
            r_assert_err(0,"lld_adv.c",0xa60);
          }
          r_lld_adv_aux_ch_idx_set(param_1);
          goto _L911;
        }
_L913:
        cVar11 = r_assert_err;
        if (param_3 == 0) {
_L978:
          *(code *)(iVar1 + 0x16) = cVar11;
        }
        else if ((uint)(*(int *)(iVar1 + 100) << 1) <=
                 (param_2 - *(int *)(iVar1 + 0x5c) & 0xfffffffU)) {
          cVar11 = (code)(*(char *)(iVar1 + 0x16) + DAT_0001700d);
          goto _L978;
        }
        *(int *)(iVar1 + 0x5c) = param_2;
        if (*(char *)(iVar1 + 0x95) != '\0') goto _L919;
_L922:
        if (*(int *)(iVar1 + 0x58) == -1) {
          *(ushort *)(iVar1 + 0x14) = DAT_0001700d & 0xf | 0x6000;
        }
        else {
          *(ushort *)(iVar1 + 0x14) = DAT_0001700d & 0xf | 0xa000;
          *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0x58);
        }
      }
      else {
_L911:
        if ((*(char *)(iVar1 + 0x95) == '\0') || (*(int *)(iVar1 + 0x38) != param_2)) goto _L913;
        cVar11 = r_emi_get_mem_addr_by_offset;
        if (param_3 == 0) {
_L977:
          *(code *)(iVar1 + 0x4a) = cVar11;
        }
        else if ((uint)(*(int *)(iVar1 + 100) << 1) <=
                 (param_2 - *(int *)(iVar1 + 0x60) & 0xfffffffU)) {
          cVar11 = (code)(*(char *)(iVar1 + 0x4a) + DAT_00017011);
          goto _L977;
        }
        *(int *)(iVar1 + 0x60) = param_2;
_L919:
        if (*(int *)(iVar1 + 4) != param_2) goto _L922;
        *(ushort *)(iVar1 + 0x14) = DAT_0001700d & 0xf | 0xa000;
        *(uint *)(iVar1 + 0xc) = *(int *)(iVar1 + 0x38) - *(int *)(iVar1 + 100) & 0xfffffff;
      }
      uVar6 = (**(code **)(_r_osi_funcs_p + 0x88))(*(code **)(_r_osi_funcs_p + 0x88));
      uVar6 = uVar6 % 0x11;
      iVar5 = uVar6 << 1;
      if (*(char *)(iVar1 + 0x95) != '\0') {
        if (uVar6 == 0) {
          iVar5 = 1;
        }
        else if (uVar6 == 0x10) {
          iVar5 = 0x1f;
        }
      }
      if (g_adv_delay_dis != '\0') {
        iVar5 = 0;
      }
      *(uint *)(iVar1 + 4) = iVar5 + *(int *)(iVar1 + 100) * 2 + param_2 & 0xfffffff;
      iVar5 = r_sch_arb_insert(iVar1);
      cVar9 = *(char *)(iVar1 + 0x95);
      if (iVar5 == 0) {
        *(undefined1 *)(iVar1 + 0x89) = 0;
        if ((cVar9 != '\0') && (*(int *)(iVar1 + 0x38) == param_2)) {
          uVar8 = *(uint *)(iVar1 + 0x58);
          uVar6 = (uint)*(byte *)(iVar1 + 0x8f) * *(int *)(iVar1 + 100) * 2 + *(int *)(iVar1 + 4) &
                  0xfffffff;
          if (uVar8 == 0xffffffff) {
            *(ushort *)(iVar1 + 0x48) = DAT_00017011 & 0xf | 0x6000;
          }
          else {
            *(ushort *)(iVar1 + 0x48) = DAT_00017011 & 0xf | 0xa000;
            *(uint *)(iVar1 + 0x40) = uVar8;
            if ((uVar6 - uVar8 & 0xfffffff) < 0x7ffffff) {
              uVar6 = uVar8;
            }
          }
          *(uint *)(iVar1 + 0x38) = uVar6;
          iVar5 = r_sch_arb_insert(iVar1 + 0x34);
          if (iVar5 != 0) {
            *(undefined1 *)(iVar1 + 0x95) = 0;
            *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x44);
          }
        }
        return;
      }
      if (cVar9 != '\0') {
        *(undefined4 *)(iVar1 + 4) = 0xffffffff;
        *(undefined1 *)(iVar1 + 0x89) = 0;
      }
      if (*(int *)(iVar1 + 0x58) == -1) {
        if (cVar9 != '\0') {
          return;
        }
        uVar7 = 0xadf;
_L980:
        r_assert_err(0,"lld_adv.c",uVar7);
        return;
      }
      if (*(int *)(iVar1 + 0x58) != *(int *)(iVar1 + 0xc)) {
        return;
      }
    }
    else {
      cVar9 = DAT_0001700e;
      if (param_3 != 0) {
        cVar9 = *(char *)(iVar1 + 0x16) + DAT_0001700f;
      }
      *(char *)(iVar1 + 0x16) = cVar9;
      *(ushort *)(iVar1 + 0x14) = bVar10 & 0xf | 0xa000;
      *(int *)(iVar1 + 4) = param_2;
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar1 + 0x58);
      iVar5 = r_sch_arb_insert(iVar1);
      if (iVar5 == 0) {
        *(undefined1 *)(iVar1 + 0x89) = 0;
        return;
      }
    }
    uVar6 = 0x3c;
  }
  iVar1 = 1;
_L979:
  iVar5 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar5 != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (((*(uint *)(iVar4 + 0x28) & 4) != 0) &&
       (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 3)) {
      r_ble_log_internal_x1
                (0x40000002,
                 (uint)*(byte *)(iVar5 + 0x89) << 0x18 | uVar6 << 0x10 | iVar1 << 8 | param_1);
    }
    if ((((*(short *)(iVar5 + 0x24) != 0) && (*(short *)(iVar5 + 0x7e) != 0)) &&
        (*(short *)(iVar5 + 0x24) != *(short *)(iVar5 + 0x7e))) &&
       (((*(ushort *)(iVar5 + 0x74) & 0x10) == 0 || ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10))))
    {
      iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar4 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar5 + 0x7e));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar5 + 0x7e));
      }
    }
    if (((*(short *)(iVar5 + 0x26) != 0) && (*(short *)(iVar5 + 0x80) != 0)) &&
       ((*(short *)(iVar5 + 0x26) != *(short *)(iVar5 + 0x80) &&
        (((*(ushort *)(iVar5 + 0x74) & 0x12) == 2 || ((*(ushort *)(iVar5 + 0x74) & 0x14) == 0x10))))
       )) {
      iVar4 = (**(code **)(_r_osi_funcs_p + 0x6c))(*(code **)(_r_osi_funcs_p + 0x6c));
      if (iVar4 == 0) {
        r_ble_util_buf_adv_tx_free(*(undefined2 *)(iVar5 + 0x80));
      }
      else {
        r_ble_util_buf_adv_tx_free_in_isr(*(undefined2 *)(iVar5 + 0x80));
      }
    }
  }
  iVar5 = *(int *)(&lld_adv_env + param_1 * 4);
  if (iVar5 != 0) {
    r_sch_arb_remove(iVar5,0);
    if (*(char *)(iVar5 + 0x95) != '\0') {
      r_sch_arb_remove(iVar5 + 0x34,0);
    }
    if ((*(ushort *)(iVar5 + 0x74) & 8) != 0) {
      r_sch_slice_fg_remove(2);
    }
    if (iVar1 != 0) {
      puVar3 = (undefined1 *)r_ke_msg_alloc(0x207,0,0xff,0x3c);
      *puVar3 = (char)param_1;
      puVar3[1] = (char)uVar6;
      puVar3[0x35] = 0;
      if ((uVar6 != 0) && (uVar6 = 0, *(short *)(iVar5 + 0x78) != 0)) {
        uVar6 = (uint)*(byte *)(iVar5 + 0x86);
      }
      puVar3[0x38] = (char)uVar6;
      r_ke_msg_send();
    }
    r_ke_free(*(undefined4 *)(&lld_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_adv_env + param_1 * 4) = 0;
  }
  return;
}


/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> arch_main.o -> btdm_controller_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 btdm_controller_init(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  code *pcVar13;
  uint uVar14;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  
  uVar10 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L243;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("Rom table is disabled\n");
  }
  (**(code **)(_r_osi_funcs_p + 0xe4))(*(code **)(_r_osi_funcs_p + 0xe4));
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2509280)) {
    if (((((uint)param_1[0xb] >> 0x10) - 1 & 0xff) < 2) &&
       ((((uint)param_1[0xb] >> 0x18) - 1 & 0xff) < 2)) {
      if (*(byte *)(param_1 + 0xc) < 2) {
        *(undefined1 *)(param_1 + 0xc) = 2;
      }
      if (*(ushort *)(param_1 + 0xd) < 0x101) {
        if (*(byte *)((int)param_1 + 0x1e) < 0x10) {
          r_sdk_config_set_opts(param_1);
          sdk_config_set_mask(param_1[8]);
          sdk_config_set_opts_ext(param_1 + 8);
          sdk_config_overwrite_priv_opts();
          sdk_config_set_derived_opts();
          iVar9 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar9 + 0x1e) == '\0') {
            uVar10 = 0xfffffff6;
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need rom lib\n");
              uVar10 = 0xfffffff6;
            }
            goto _L243;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar9 = r_h4tl_eif_register(param_1[6]), iVar9 != 0)) goto _L351;
          iVar9 = r_sdk_config_get_opts();
          uStack_40._0_2_ = CONCAT11(DAT_00013047,*(undefined1 *)(iVar9 + 0xd));
          r_sdk_config_set_hl_derived_opts(&uStack_40);
          if (DAT_00013046 == 0) {
            btdm_hli_get_null_funcs();
          }
          else {
            btdm_hli_get_funcs();
          }
          btdm_hli_funcs_register();
          _btdm_env_p = (int *)(**(code **)(_r_osi_funcs_p + 0x74))
                                         (0x28,*(code **)(_r_osi_funcs_p + 0x74));
          if (_btdm_env_p == (int *)0x0) {
            uVar10 = 0x80a8021d;
          }
          else {
            memset(_btdm_env_p,0,0x28);
            uVar11 = r_lld_env_init();
            iVar9 = r_llm_env_init();
            if (iVar9 == 0) {
              uVar11 = 0;
            }
            iVar9 = r_ble_util_buf_env_init();
            if (iVar9 == 0) {
              uVar11 = 0;
            }
            if ((DAT_00013045 != '\0') && (iVar9 = r_flash_env_init(), iVar9 == 0)) {
              uVar11 = 0;
            }
            iVar9 = r_hci_tl_env_init();
            if ((iVar9 == 0) || ((uVar11 & 1) == 0)) {
              uVar10 = 0x80a8021e;
            }
            else {
              iVar9 = r_sdk_config_get_opts();
              bVar1 = *(byte *)(iVar9 + 0xd);
              iVar9 = r_sdk_config_get_opts();
              bVar2 = *(byte *)(iVar9 + 0xd);
              uVar14 = (uint)DAT_00013047;
              iVar9 = r_sdk_config_get_opts();
              piVar6 = _btdm_env_p;
              uVar11 = (uint)DAT_00013046;
              if (uVar11 != 0) {
                uVar11 = uVar14 * 0xe0 + (uint)*(byte *)(iVar9 + 0xd) * 0x88;
              }
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar2 + 2) * 0xc + (uint)bVar1 * 0xe6 + 0x25b + uVar11 & 0xfffffffc) + 0xc;
              iVar9 = (*pcVar13)(pcVar13);
              *piVar6 = iVar9;
              iVar9 = r_sdk_config_get_opts();
              bVar1 = *(byte *)(iVar9 + 0xd);
              iVar12 = r_sdk_config_get_opts_ext();
              piVar6 = _btdm_env_p;
              iVar9 = ((uint)bVar1 * 0x104 + 0x8ef) * 2;
              if (*(char *)(iVar12 + 0x18) != '\0') {
                iVar9 = iVar9 + 0x672;
              }
              uVar11 = 0;
              if (DAT_00013046 != 0) {
                uVar11 = (uint)DAT_00013047 * 400;
                if ((uint)DAT_00013047 * 400 < 0x1800) {
                  uVar11 = 0x1800;
                }
              }
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] = (iVar9 + 3 + uVar11 & 0xfffffffc) + 0xc;
              iVar9 = (*pcVar13)(pcVar13);
              piVar6[2] = iVar9;
              iVar9 = r_sdk_config_get_opts_ext();
              iVar12 = 0x290;
              if (*(char *)(iVar9 + 0x23) != '\0') {
                iVar9 = r_sdk_config_get_opts_ext();
                uVar4 = *(ushort *)(iVar9 + 8);
                iVar9 = r_sdk_config_get_opts_ext();
                iVar12 = (uint)*(ushort *)(iVar9 + 6) * 0xc + (uint)uVar4 * 0x10 + 0x290;
              }
              piVar6 = _btdm_env_p;
              pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] = iVar12 + 0xc;
              iVar9 = (*pcVar13)(pcVar13);
              bVar1 = DAT_00013046;
              piVar6[4] = iVar9;
              piVar6 = _btdm_env_p;
              if (bVar1 != 0) {
                pcVar13 = *(code **)(_r_osi_funcs_p + 0x78);
                _btdm_env_p[7] = 0xc0c;
                iVar9 = (*pcVar13)(pcVar13);
                piVar6[6] = iVar9;
              }
              if ((((*_btdm_env_p != 0) && (_btdm_env_p[2] != 0)) && (_btdm_env_p[4] != 0)) &&
                 ((_btdm_env_p[7] == 0 || (_btdm_env_p[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,_btdm_env_p[1],_btdm_env_p[3],_btdm_env_p[5],_btdm_env_p[6]);
                }
                iVar9 = r_sdk_config_get_opts();
                if ((*(char *)(iVar9 + 0x17) != '\0') &&
                   (iVar9 = r_sdk_config_get_opts(), piVar6 = _btdm_env_p,
                   *(char *)(iVar9 + 0x17) == '\x01')) {
                  iVar9 = (**(code **)(_r_osi_funcs_p + 0x78))
                                    (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar7 = _btdm_env_p;
                  piVar6[9] = iVar9;
                  if ((void *)piVar7[9] == (void *)0x0) {
                    uVar10 = 0x80a80220;
                    goto _L350;
                  }
                  memset((void *)piVar7[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                uStack_40 = *_btdm_env_p;
                iStack_3c = _btdm_env_p[1];
                iStack_38 = _btdm_env_p[2];
                iStack_34 = _btdm_env_p[3];
                iStack_30 = _btdm_env_p[4];
                iStack_2c = _btdm_env_p[5];
                iStack_28 = _btdm_env_p[6];
                iStack_24 = _btdm_env_p[7];
                r_ble_log_internal_hex(0x40a80221,0x20,&uStack_40);
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar10 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar10 = 0xfffffffa;
                  }
                  else {
                    pcVar13 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar9 = r_btdm_vnd_ol_task_env_get();
                    uVar10 = (*pcVar13)(1,0);
                    *(undefined4 *)(iVar9 + 8) = uVar10;
                    iVar9 = r_btdm_vnd_ol_task_env_get();
                    if (*(int *)(iVar9 + 8) == 0) {
                      uVar10 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))
                                     (1,1,*(code **)(_r_osi_funcs_p + 0x24));
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      pcVar13 = *(code **)(_r_osi_funcs_p + 100);
                      iVar9 = r_sdk_config_get_opts();
                      uVar5 = *(undefined2 *)(iVar9 + 8);
                      iVar9 = r_sdk_config_get_opts();
                      uVar3 = *(undefined1 *)(iVar9 + 10);
                      iVar9 = r_sdk_config_get_opts();
                      iVar9 = (*pcVar13)(btdm_controller_task,"btController",uVar5,0,uVar3,
                                         &g_rw_controller_task_handle,*(undefined1 *)(iVar9 + 0xb));
                      uVar10 = 0xfffffff7;
                      if (iVar9 == 1) {
                        r_btdm_task_post_hack(7,0,0,1);
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        iVar9 = r_sdk_config_get_opts();
                        r_ble_log_internal_x2(0x40a80223,0,*(undefined1 *)(iVar9 + 0xb));
                        return 0;
                      }
                    }
                  }
                }
                goto _L243;
              }
              uVar10 = 0x80a8021f;
            }
          }
_L350:
          r_ble_log_internal_x0(uVar10);
          r_lld_env_deinit();
          r_llm_env_deinit();
          r_ble_util_buf_env_deinit();
          if (DAT_00013045 != '\0') {
            r_flash_env_deinit();
          }
          r_hci_tl_env_deinit();
          if (*_btdm_env_p != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            *_btdm_env_p = 0;
          }
          if (_btdm_env_p[2] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[2] = 0;
          }
          if (_btdm_env_p[4] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[4] = 0;
          }
          if (_btdm_env_p[6] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[6] = 0;
          }
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[9] = 0;
          }
          uVar10 = 0xfffffffc;
          if (_btdm_env_p != (int *)0x0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p = (int *)0x0;
          }
          goto _L243;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar8 = "Default Tx Power Invalid: 0x%x\n";
          goto _L352;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar8 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L352;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar8 = "Hardware Target Code Invalid: 0x%x\n";
_L352:
      ets_printf(pcVar8);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2509280);
  }
_L351:
  uVar10 = 0xfffffffd;
_L243:
  btdm_controller_deinit_internal();
  r_ble_log_internal_x1(0x80a80224,uVar10);
  return uVar10;
}


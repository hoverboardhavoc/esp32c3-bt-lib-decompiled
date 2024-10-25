/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
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
  bool bVar6;
  int *piVar7;
  int *piVar8;
  char cVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  code *pcVar14;
  uint uVar15;
  undefined1 uStack_34;
  undefined1 uStack_33;
  
  uVar13 = 0xffffffff;
  if (_g_rw_init_sem != 0) goto _L240;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("Rom table is disabled\n");
  }
  (**(code **)(_r_osi_funcs_p + 0xe4))(*(code **)(_r_osi_funcs_p + 0xe4));
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2410230)) {
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
          iVar11 = r_sdk_config_get_opts_ext();
          if (*(char *)(iVar11 + 0x1e) == '\0') {
            uVar13 = 0xfffffff6;
            if (0 < _g_bt_plf_log_level) {
              ets_printf("Controller lib error, need rom lib\n");
              uVar13 = 0xfffffff6;
            }
            goto _L240;
          }
          if ((*(char *)((int)param_1 + 0x17) == '\0') &&
             (iVar11 = r_h4tl_eif_register(param_1[6]), iVar11 != 0)) goto _L345;
          iVar11 = r_sdk_config_get_opts();
          uStack_34 = *(undefined1 *)(iVar11 + 0xd);
          uStack_33 = DAT_00012037;
          r_sdk_config_set_hl_derived_opts(&uStack_34);
          if (((uint)_btdm_env_p >> 0x10 & 0xff) == 0) {
            btdm_hli_get_null_funcs();
          }
          else {
            btdm_hli_get_funcs();
          }
          btdm_hli_funcs_register();
          _btdm_env_p = (int *)(**(code **)(_r_osi_funcs_p + 0x74))
                                         (0x28,*(code **)(_r_osi_funcs_p + 0x74));
          if (_btdm_env_p != (int *)0x0) {
            memset(_btdm_env_p,0,0x28);
            iVar11 = r_lld_env_init();
            iVar12 = r_llm_env_init();
            if (iVar12 == 0) {
              iVar11 = 0;
            }
            iVar12 = r_ble_util_buf_env_init();
            bVar6 = iVar12 != 0 && iVar11 != 0;
            if ((((uint)_btdm_env_p >> 8 & 0xff) != 0) && (iVar11 = r_flash_env_init(), iVar11 == 0)
               ) {
              bVar6 = false;
            }
            iVar11 = r_hci_tl_env_init();
            if ((iVar11 != 0) && (bVar6)) {
              iVar11 = r_sdk_config_get_opts();
              bVar1 = *(byte *)(iVar11 + 0xd);
              iVar11 = r_sdk_config_get_opts();
              bVar2 = *(byte *)(iVar11 + 0xd);
              uVar15 = (uint)_btdm_env_p >> 0x18;
              iVar11 = r_sdk_config_get_opts();
              piVar7 = _btdm_env_p;
              iVar12 = 0;
              if (((uint)_btdm_env_p >> 0x10 & 0xff) != 0) {
                iVar12 = uVar15 * 0xe0 + (uint)*(byte *)(iVar11 + 0xd) * 0x88;
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar2 + 2) * 0xc + (uint)bVar1 * 0xe6 + 0x25b + iVar12 & 0xfffffffc) + 0xc;
              iVar11 = (*pcVar14)(pcVar14);
              *piVar7 = iVar11;
              iVar11 = r_sdk_config_get_opts();
              piVar7 = _btdm_env_p;
              uVar15 = 0;
              if (((uint)_btdm_env_p >> 0x10 & 0xff) != 0) {
                uVar15 = ((uint)_btdm_env_p >> 0x18) * 400;
                if (uVar15 < 0x1800) {
                  uVar15 = 0x1800;
                }
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar11 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar15 &
                   0xfffffffc) + 0xc;
              iVar11 = (*pcVar14)(pcVar14);
              piVar7[2] = iVar11;
              iVar11 = r_sdk_config_get_opts_ext();
              uVar4 = *(ushort *)(iVar11 + 8);
              iVar11 = r_sdk_config_get_opts_ext();
              piVar7 = _btdm_env_p;
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[5] = (uint)*(ushort *)(iVar11 + 6) * 0xc + (uint)uVar4 * 0x10 + 0x29c;
              iVar11 = (*pcVar14)(pcVar14);
              cVar9 = DAT_00012036;
              piVar7[4] = iVar11;
              piVar7 = _btdm_env_p;
              if (cVar9 != '\0') {
                pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
                _btdm_env_p[7] = 0xc0c;
                iVar11 = (*pcVar14)(pcVar14);
                piVar7[6] = iVar11;
              }
              if ((((*_btdm_env_p != 0) && (_btdm_env_p[2] != 0)) && (_btdm_env_p[4] != 0)) &&
                 ((_btdm_env_p[7] == 0 || (_btdm_env_p[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,_btdm_env_p[1],_btdm_env_p[3],_btdm_env_p[5],_btdm_env_p[6]);
                }
                iVar11 = r_sdk_config_get_opts();
                if ((*(char *)(iVar11 + 0x17) != '\0') &&
                   (iVar11 = r_sdk_config_get_opts(), piVar7 = _btdm_env_p,
                   *(char *)(iVar11 + 0x17) == '\x01')) {
                  iVar11 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar8 = _btdm_env_p;
                  piVar7[9] = iVar11;
                  if ((void *)piVar8[9] == (void *)0x0) goto _L257;
                  memset((void *)piVar8[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar13 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar13 = 0xfffffffa;
                  }
                  else {
                    pcVar14 = *(code **)(_r_osi_funcs_p + 0x24);
                    iVar11 = r_btdm_vnd_ol_task_env_get();
                    uVar13 = (*pcVar14)(1,0);
                    *(undefined4 *)(iVar11 + 8) = uVar13;
                    iVar11 = r_btdm_vnd_ol_task_env_get();
                    if (*(int *)(iVar11 + 8) == 0) {
                      uVar13 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))
                                     (1,1,*(code **)(_r_osi_funcs_p + 0x24));
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      uVar13 = 0xfffffff7;
                      pcVar14 = *(code **)(_r_osi_funcs_p + 100);
                      iVar11 = r_sdk_config_get_opts();
                      uVar5 = *(undefined2 *)(iVar11 + 8);
                      iVar11 = r_sdk_config_get_opts();
                      uVar3 = *(undefined1 *)(iVar11 + 10);
                      iVar11 = r_sdk_config_get_opts();
                      iVar11 = (*pcVar14)(btdm_controller_task,"btController",uVar5,0,uVar3,
                                          &g_rw_controller_task_handle,*(undefined1 *)(iVar11 + 0xb)
                                         );
                      if (iVar11 == 1) {
                        r_btdm_task_post(7,0,0,1);
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        return 0;
                      }
                    }
                  }
                }
                goto _L240;
              }
            }
          }
_L257:
          r_lld_env_deinit();
          r_llm_env_deinit();
          r_ble_util_buf_env_deinit();
          if (((uint)_btdm_env_p >> 8 & 0xff) != 0) {
            r_flash_env_deinit();
          }
          r_hci_tl_env_deinit();
          if (*_btdm_env_p != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[2] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[4] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[6] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
          }
          if (_btdm_env_p[9] != 0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p[9] = 0;
          }
          uVar13 = 0xfffffffc;
          if (_btdm_env_p != (int *)0x0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p = (int *)0x0;
          }
          goto _L240;
        }
        if (0 < _g_bt_plf_log_level) {
          pcVar10 = "Default Tx Power Invalid: 0x%x\n";
          goto _L346;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar10 = "Invalid scan backoff upperlimitmax: 0x%x\n";
        goto _L346;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar10 = "Hardware Target Code Invalid: 0x%x\n";
_L346:
      ets_printf(pcVar10);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2410230);
  }
_L345:
  uVar13 = 0xfffffffd;
_L240:
  btdm_controller_deinit_internal();
  return uVar13;
}


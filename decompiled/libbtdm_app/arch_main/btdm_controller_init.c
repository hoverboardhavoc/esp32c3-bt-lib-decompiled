/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> arch_main.o -> btdm_controller_init
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
  undefined2 uVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  char cVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  code *pcVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined1 uStack_34;
  byte bStack_33;
  
  if (_g_rw_init_sem != 0) {
    return 0xffffffff;
  }
  _r_plf_funcs_p =
       (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0xf0,*(code **)(_r_osi_funcs_p + 0x78));
  if (((_r_plf_funcs_p == (void *)0x0) ||
      (_r_modules_funcs_p =
            (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x3c0,*(code **)(_r_osi_funcs_p + 0x78)),
      _r_modules_funcs_p == (void *)0x0)) ||
     (_r_ip_funcs_p =
           (void *)(**(code **)(_r_osi_funcs_p + 0x78))(0x7c8,*(code **)(_r_osi_funcs_p + 0x78)),
     _r_ip_funcs_p == (void *)0x0)) {
    if (0 < _g_bt_plf_log_level) {
      ets_printf("Funcs table create fails\n");
    }
    btdm_funcs_table_destroy();
    return 0xfffffffe;
  }
  memcpy(_r_plf_funcs_p,&r_plf_funcs_ro,0xf0);
  memcpy(_r_modules_funcs_p,&r_modules_funcs_ro,0x3c0);
  memcpy(_r_ip_funcs_p,&r_ip_funcs_ro,0x7c8);
  (**(code **)((int)_r_plf_funcs_p + 0x1c))(*(code **)((int)_r_plf_funcs_p + 0x1c));
  config_funcs_reset();
  if ((*param_1 == 0x5a5aa5a5) && (param_1[1] == 0x2112280)) {
    if (((((uint)param_1[0xb] >> 0x10) - 1 & 0xff) < 2) &&
       ((((uint)param_1[0xb] >> 0x18) - 1 & 0xff) < 2)) {
      if (*(byte *)(param_1 + 0xc) < 2) {
        *(undefined1 *)(param_1 + 0xc) = 2;
      }
      if (*(byte *)((int)param_1 + 0x1e) < 0x10) {
        (**(code **)((int)_r_plf_funcs_p + 0x44))(param_1,*(code **)((int)_r_plf_funcs_p + 0x44));
        sdk_config_set_mask(param_1[8]);
        sdk_config_set_opts_ext(param_1 + 8);
        sdk_config_overwrite_priv_opts();
        sdk_config_set_derived_opts();
        if ((*(char *)((int)param_1 + 0x17) != '\0') ||
           (iVar10 = (**(code **)((int)_r_plf_funcs_p + 0xe8))
                               (param_1[6],*(code **)((int)_r_plf_funcs_p + 0xe8)), iVar10 == 0)) {
          iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))(*(code **)((int)_r_plf_funcs_p + 0x38))
          ;
          uStack_34 = *(undefined1 *)(iVar10 + 0xd);
          bStack_33 = DAT_00012023;
          (**(code **)((int)_r_plf_funcs_p + 0x24))
                    (&uStack_34,*(code **)((int)_r_plf_funcs_p + 0x24));
          if (DAT_00012022 == '\0') {
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
            iVar10 = (**(code **)((int)_r_ip_funcs_p + 0x244))
                               (*(code **)((int)_r_ip_funcs_p + 0x244));
            iVar11 = (**(code **)((int)_r_ip_funcs_p + 0x4d0))
                               (*(code **)((int)_r_ip_funcs_p + 0x4d0));
            if (iVar11 == 0) {
              iVar10 = 0;
            }
            iVar11 = (**(code **)((int)_r_ip_funcs_p + 0xe4))(*(code **)((int)_r_ip_funcs_p + 0xe4))
            ;
            iVar12 = (**(code **)((int)_r_plf_funcs_p + 0x4c))
                               (*(code **)((int)_r_plf_funcs_p + 0x4c));
            iVar13 = (**(code **)((int)_r_ip_funcs_p + 0x44))(*(code **)((int)_r_ip_funcs_p + 0x44))
            ;
            if ((iVar13 != 0) && (iVar12 != 0 && (iVar11 != 0 && iVar10 != 0))) {
              iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar1 = *(byte *)(iVar10 + 0xd);
              iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              bVar2 = *(byte *)(iVar10 + 0xd);
              uVar16 = (uint)DAT_00012023;
              iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                 (*(code **)((int)_r_plf_funcs_p + 0x38));
              piVar6 = _btdm_env_p;
              iVar11 = 0;
              if (DAT_00012022 != '\0') {
                iVar11 = uVar16 * 0xe0 + (uint)*(byte *)(iVar10 + 0xd) * 0x88;
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[1] =
                   ((bVar2 + 2) * 0xc + (uint)bVar1 * 0xe6 + 0x25b + iVar11 & 0xfffffffc) + 0xc;
              iVar10 = (*pcVar14)(pcVar14);
              pvVar5 = _r_plf_funcs_p;
              *piVar6 = iVar10;
              iVar10 = (**(code **)((int)pvVar5 + 0x38))(*(code **)((int)pvVar5 + 0x38));
              piVar6 = _btdm_env_p;
              uVar16 = 0;
              if (DAT_00012022 != '\0') {
                uVar16 = (uint)DAT_00012023 * 400;
                if ((uint)DAT_00012023 * 400 < 0x1800) {
                  uVar16 = 0x1800;
                }
              }
              pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
              _btdm_env_p[3] =
                   (((uint)*(byte *)(iVar10 + 0xd) * 0x104 + 0x8ef) * 2 + 0x675 + uVar16 &
                   0xfffffffc) + 0xc;
              iVar10 = (*pcVar14)(pcVar14);
              piVar6[2] = iVar10;
              piVar6 = _btdm_env_p;
              _btdm_env_p[5] = 0x29c;
              iVar10 = (**(code **)(_r_osi_funcs_p + 0x78))(0x29c,*(code **)(_r_osi_funcs_p + 0x78))
              ;
              cVar8 = DAT_00012022;
              piVar6[4] = iVar10;
              piVar6 = _btdm_env_p;
              if (cVar8 != '\0') {
                pcVar14 = *(code **)(_r_osi_funcs_p + 0x78);
                _btdm_env_p[7] = 0xc0c;
                iVar10 = (*pcVar14)(pcVar14);
                piVar6[6] = iVar10;
              }
              if ((((*_btdm_env_p != 0) && (_btdm_env_p[2] != 0)) && (_btdm_env_p[4] != 0)) &&
                 ((_btdm_env_p[7] == 0 || (_btdm_env_p[6] != 0)))) {
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("RWIP Heap alloc: ENV [%p %d], MSG [%p %d], NORET [%p %d], DB [%p %d]\n"
                             ,_btdm_env_p[1],_btdm_env_p[3],_btdm_env_p[5],_btdm_env_p[6]);
                }
                iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                   (*(code **)((int)_r_plf_funcs_p + 0x38));
                if ((*(char *)(iVar10 + 0x17) != '\0') &&
                   (iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                       (*(code **)((int)_r_plf_funcs_p + 0x38)),
                   piVar6 = _btdm_env_p, *(char *)(iVar10 + 0x17) == '\x01')) {
                  iVar10 = (**(code **)(_r_osi_funcs_p + 0x78))
                                     (0xc,*(code **)(_r_osi_funcs_p + 0x78));
                  piVar7 = _btdm_env_p;
                  piVar6[9] = iVar10;
                  if ((void *)piVar7[9] == (void *)0x0) goto _L239;
                  memset((void *)piVar7[9],0,0xc);
                }
                if (2 < _g_bt_plf_log_level) {
                  ets_printf("Uart ENV [%p], VHCI ENV [%p]\n",_btdm_env_p[8],_btdm_env_p[9]);
                }
                _g_rw_init_sem =
                     (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24));
                if (_g_rw_init_sem == 0) {
                  uVar15 = 0xfffffffb;
                }
                else {
                  _g_rw_schd_queue =
                       (**(code **)(_r_osi_funcs_p + 0x4c))(5,8,*(code **)(_r_osi_funcs_p + 0x4c));
                  if (_g_rw_schd_queue == 0) {
                    uVar15 = 0xfffffffa;
                  }
                  else {
                    _g_rw_schd_sem =
                         (**(code **)(_r_osi_funcs_p + 0x24))(1,0,*(code **)(_r_osi_funcs_p + 0x24))
                    ;
                    if (_g_rw_schd_sem == 0) {
                      uVar15 = 0xfffffff9;
                    }
                    else {
                      _g_waking_sleeping_sem =
                           (**(code **)(_r_osi_funcs_p + 0x24))
                                     (1,1,*(code **)(_r_osi_funcs_p + 0x24));
                      if (_g_waking_sleeping_sem == 0) {
                        return 0xfffffff8;
                      }
                      pcVar14 = *(code **)(_r_osi_funcs_p + 100);
                      iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar4 = *(undefined2 *)(iVar10 + 8);
                      iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      uVar3 = *(undefined1 *)(iVar10 + 10);
                      iVar10 = (**(code **)((int)_r_plf_funcs_p + 0x38))
                                         (*(code **)((int)_r_plf_funcs_p + 0x38));
                      iVar10 = (*pcVar14)(btdm_controller_task,"btController",uVar4,0,uVar3,
                                          &g_rw_controller_task_handle,*(undefined1 *)(iVar10 + 0xb)
                                         );
                      if (iVar10 == 1) {
                        (**(code **)((int)_r_plf_funcs_p + 0x28))
                                  (7,0,0,1,*(code **)((int)_r_plf_funcs_p + 0x28));
                        (**(code **)(_r_osi_funcs_p + 0x34))
                                  (_g_rw_init_sem,10000,*(code **)(_r_osi_funcs_p + 0x34));
                        return 0;
                      }
                      uVar15 = 0xfffffff7;
                      (**(code **)(_r_osi_funcs_p + 0x28))
                                (_g_waking_sleeping_sem,*(code **)(_r_osi_funcs_p + 0x28));
                      _g_waking_sleeping_sem = 0;
                      (**(code **)(_r_osi_funcs_p + 0x28))
                                (_g_rw_schd_sem,*(code **)(_r_osi_funcs_p + 0x28));
                    }
                    _g_rw_schd_sem = 0;
                    (**(code **)(_r_osi_funcs_p + 0x50))
                              (_g_rw_schd_queue,*(code **)(_r_osi_funcs_p + 0x50));
                  }
                  _g_rw_schd_queue = 0;
                  (**(code **)(_r_osi_funcs_p + 0x28))
                            (_g_rw_init_sem,*(code **)(_r_osi_funcs_p + 0x28));
                }
                _g_rw_init_sem = 0;
                btdm_controller_env_deinit();
                goto _L228;
              }
            }
          }
_L239:
          (**(code **)((int)_r_ip_funcs_p + 0x240))(*(code **)((int)_r_ip_funcs_p + 0x240));
          (**(code **)((int)_r_ip_funcs_p + 0x4cc))(*(code **)((int)_r_ip_funcs_p + 0x4cc));
          (**(code **)((int)_r_ip_funcs_p + 0xe0))(*(code **)((int)_r_ip_funcs_p + 0xe0));
          (**(code **)((int)_r_plf_funcs_p + 0x48))(*(code **)((int)_r_plf_funcs_p + 0x48));
          (**(code **)((int)_r_ip_funcs_p + 0x40))(*(code **)((int)_r_ip_funcs_p + 0x40));
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
          uVar15 = 0xfffffffc;
          if (_btdm_env_p != (int *)0x0) {
            (**(code **)(_r_osi_funcs_p + 0x7c))(*(code **)(_r_osi_funcs_p + 0x7c));
            _btdm_env_p = (int *)0x0;
            uVar15 = 0xfffffffc;
          }
          goto _L228;
        }
      }
      else if (0 < _g_bt_plf_log_level) {
        pcVar9 = "Default Tx Power Invalid: 0x%x\n";
        goto _L335;
      }
    }
    else if (0 < _g_bt_plf_log_level) {
      pcVar9 = "Hardware Target Code Invalid: 0x%x\n";
_L335:
      ets_printf(pcVar9);
    }
  }
  else if (0 < _g_bt_plf_log_level) {
    ets_printf("Config struct mismatch: magic=%08x, ver=%08x\n",0x5a5aa5a5,0x2112280);
  }
  uVar15 = 0xfffffffd;
_L228:
  btdm_funcs_table_destroy();
  return uVar15;
}

